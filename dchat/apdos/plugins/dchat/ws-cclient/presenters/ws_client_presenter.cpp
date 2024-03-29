#include "ws_client_presenter.h"
#include <boost/version.hpp>
#include <apdos/plugins/dchat/connecter/events/req_login.h>
#include <apdos/plugins/dchat/connecter/events/res_login.h>
#include <apdos/plugins/dchat/connecter/events/res_error.h>
#include <apdos/kernel/kernel.h>
#include <apdos/kernel/actor/actor.h>
#include <apdos/plugins/ws_net/ws_actor_connecter.h>
#include <apdos/plugins/dchat/connecter/presenters/client_presenter.h>
#include <apdos/plugins/dchat/connecter/presenters/client_listener_presenter.h>
#include <apdos/plugins/dchat/connecter/models/auth.h>
#include <apdos/plugins/dchat/connecter/models/rooms.h>
#include <apdos/plugins/dchat/connecter/models/room_users.h>
#include <apdos/plugins/ws_net/ws_actor_connecter_event.h>
#include "../models/line_input.h"
#include "../presenters/wait_room_cmd_presenter.h"
#include "../presenters/chat_room_cmd_presenter.h"
#include "../models/events/line_input_event.h"

using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace std;
using namespace boost;

using namespace apdos::kernel;
using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::ws_net;
using namespace apdos::plugins::ws_net::events;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;
typedef boost::shared_ptr<Actor> Actor_Shared_Ptr;

void Ws_Client_Presenter::start(const std::string host_address) {
  this->host_address = host_address;
  Actor_Shared_Ptr actor = Kernel::get_instance()->new_object<Actor>("/sys/connecter");
  actor_connecter = actor->add_component<Ws_Actor_Connecter>();

  Actor_Shared_Ptr line_input_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/line_input");
  boost::shared_ptr<Line_Input> line_input = line_input_actor->add_component<Line_Input>();
  line_input->set_component(actor_connecter);

  Actor_Shared_Ptr auth_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/auth");
  boost::shared_ptr<Auth> auth = auth_actor->add_component<Auth>();

  Actor_Shared_Ptr rooms_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/rooms");
  boost::shared_ptr<Rooms> rooms = rooms_actor->add_component<Rooms>();

  Actor_Shared_Ptr room_users_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/room_users");
  boost::shared_ptr<Room_Users> room_users = room_users_actor->add_component<Room_Users>();

  Actor_Shared_Ptr client_presenter_actor = Kernel::get_instance()->new_object<Actor>(
    "/sys/presenters/client_presenter");
  boost::shared_ptr<Client_Presenter> client_presenter = client_presenter_actor->add_component<Client_Presenter>();
  client_presenter->set_component(actor_connecter);

  boost::shared_ptr<Client_Listener_Presenter> client_listener_presenter = 
    client_presenter_actor->add_component<Client_Listener_Presenter>();
  client_listener_presenter->set_component(auth, rooms, room_users, client_presenter);

  Actor_Shared_Ptr wait_room_cmd_presenter_actor = Kernel::get_instance()->new_object<Actor>(
    "/sys/presenter/wait_room_cmd_presenter");
  boost::shared_ptr<Wait_Room_Cmd_Presenter> wait_room_cmd_presenter = 
    wait_room_cmd_presenter_actor->add_component<Wait_Room_Cmd_Presenter>();
  wait_room_cmd_presenter->set_components(client_presenter);

  Actor_Shared_Ptr chat_room_cmd_presenter_actor = Kernel::get_instance()->new_object<Actor>(
    "/sys/presenter/chat_room_cmd_presenter");
  boost::shared_ptr<Chat_Room_Cmd_Presenter> chat_room_cmd_presenter = 
    chat_room_cmd_presenter_actor->add_component<Chat_Room_Cmd_Presenter>();
  chat_room_cmd_presenter->set_components(client_presenter);

  Actor_Shared_Ptr cmd_presenter_actor = Kernel::get_instance()->new_object<Actor>("/sys/presenter/cmd_presenter");
  cmd_presenter = cmd_presenter_actor->add_component<Cmd_Presenter>();
  cmd_presenter->set_components(auth, line_input, wait_room_cmd_presenter, chat_room_cmd_presenter);

  actor_connecter->connect(host_address);
  actor_connecter->add_event_listener(Ws_Actor_Connecter_Event::CONNECTED, boost::bind(&Ws_Client_Presenter::on_res_connected, this, _1));
  actor_connecter->add_event_listener(Ws_Actor_Connecter_Event::DISCONNECTED, boost::bind(&Ws_Client_Presenter::on_res_disconnected, this, _1));
  actor_connecter->add_event_listener(Ws_Actor_Connecter_Event::CONNECT_FAILED, boost::bind(&Ws_Client_Presenter::on_connect_failed, this, _1));
  client_listener_presenter->add_event_listener(Res_Login::RES_LOGIN, boost::bind(&Ws_Client_Presenter::on_res_login, this, _1));
  client_listener_presenter->add_event_listener(Res_Error::RES_ERROR, boost::bind(&Ws_Client_Presenter::on_res_error, this, _1)); 
  cmd_presenter->poll();
  actor_connecter->disconnect();
}

void Ws_Client_Presenter::on_res_connected(apdos::kernel::event::Event& event) {
  std::cout << "Conncect successed" << std::endl;
}

void Ws_Client_Presenter::on_res_disconnected(apdos::kernel::event::Event& event) {
  std::cout << "Disconnected" << std::endl;
}

void Ws_Client_Presenter::on_connect_failed(apdos::kernel::event::Event& event) {
  std::cout << "Connect failed" << std::endl;
  actor_connecter->connect(host_address);
}

void Ws_Client_Presenter::on_res_login(apdos::kernel::event::Event& event) {
  Res_Login* res_login = (Res_Login*)&event;
  std::cout << res_login->get_user_id() << std::endl;
  std::cout << res_login->get_user_name() << std::endl;
}

void Ws_Client_Presenter::on_res_error(apdos::kernel::event::Event& event) {
  Res_Error* res_error = (Res_Error*)&event;
  std::cout << "Error event occured" << std::endl;
  std::cout << "code: " << res_error->get_error_code() << std::endl;
  std::cout << "message: " << res_error->get_error_message() << std::endl;
}
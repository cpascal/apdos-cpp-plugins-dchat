#include <iostream>
#include <string>
#include <boost/version.hpp>
#include <boost/asio.hpp>
#include <events/req_login.h>
#include <events/res_login.h>
#include <libs/apdos/kernel/kernel.h>
#include <libs/apdos/kernel/actor/actor.h>
#include <libs/apdos/kernel/actor/actor_connecter.h>
#include <presenters/client_presenter.h>
#include <presenters/client_listener_presenter.h>
#include <models/auth.h>
#include <models/rooms.h>
#include "models/line_input.h"
#include "presenters/cmd_presenter.h"
#include "models/events/line_input_event.h"

using namespace std;
using namespace boost;
using namespace boost::system;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace apdos::kernel;
using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;

typedef boost::shared_ptr<Actor> Actor_Shared_Ptr;
const char* HOST_ADDRESS = "tcp://211.50.119.84:10001";

int main() {
	Actor_Shared_Ptr actor = Kernel::get_instance()->new_object<Actor>("/sys/connecter");
	boost::shared_ptr<Actor_Connecter> actor_connecter = actor->add_component<Actor_Connecter>();
	
	Actor_Shared_Ptr line_input_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/line_input");
	boost::shared_ptr<Line_Input> line_input = line_input_actor->add_component<Line_Input>();

	Actor_Shared_Ptr auth_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/auth");
	boost::shared_ptr<Auth> auth = auth_actor->add_component<Auth>();

	Actor_Shared_Ptr rooms_actor = Kernel::get_instance()->new_object<Actor>("/sys/models/rooms");
	boost::shared_ptr<Rooms> rooms = rooms_actor->add_component<Rooms>();

	Actor_Shared_Ptr client_presenter_actor = Kernel::get_instance()->new_object<Actor>(
    "/sys/presenters/client_presenter");
	boost::shared_ptr<Client_Presenter> client_presenter = client_presenter_actor->add_component<Client_Presenter>();
	client_presenter->set_component(actor_connecter);

	boost::shared_ptr<Client_Listener_Presenter> client_listener_presenter = 
    client_presenter_actor->add_component<Client_Listener_Presenter>();
	client_listener_presenter->set_component(auth, rooms, client_presenter);

	Actor_Shared_Ptr cmd_presenter_actor = Kernel::get_instance()->new_object<Actor>("/sys/presenter/cmd_presenter");
	boost::shared_ptr<Cmd_Presenter> cmd_presenter = cmd_presenter_actor->add_component<Cmd_Presenter>();
	cmd_presenter->set_components(line_input, client_presenter);

	actor_connecter->connect(HOST_ADDRESS);
	cmd_presenter->poll();
	actor_connecter->disconnect();
	return 0;
}
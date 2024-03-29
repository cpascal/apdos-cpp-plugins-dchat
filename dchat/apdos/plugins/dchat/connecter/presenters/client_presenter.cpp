#include "client_presenter.h"
#include <apdos/plugins/dchat/connecter/events/req_login.h>
#include <apdos/plugins/dchat/connecter/events/req_logout.h>
#include <apdos/plugins/dchat/connecter/events/req_add_room.h>
#include <apdos/plugins/dchat/connecter/events/req_join_room.h>
#include <apdos/plugins/dchat/connecter/events/req_leave_room.h>
#include <apdos/plugins/dchat/connecter/events/req_user_chat.h>
#include <apdos/plugins/dchat/connecter/events/req_chat_history.h>

using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::presenters;

void Client_Presenter::set_component(Actor_Connecter_Shared_Ptr actor_connecter) {
  this->actor_connecter = actor_connecter;
}

void Client_Presenter::login(std::string user_name) {
  Req_Login req_login(user_name);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_login);
}

void Client_Presenter::logout() {
  Req_Logout req_logout;
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_logout);
}

void Client_Presenter::add_room(std::string room_type, std::string room_name) {
  Req_Add_Room req_add_room(room_type, room_name);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_add_room);
}

void Client_Presenter::join_room(apdos::plugins::uuid::Object_Id room_id) {
  Req_Join_Room req_join_room(room_id);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_join_room);
}

void Client_Presenter::leave_room() {
  Req_Leave_Room req_leave_room;
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_leave_room);
}

void Client_Presenter::user_chat(std::string message) {
  Req_User_Chat req_user_chat(message);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_user_chat);
}

void Client_Presenter::chat_history(apdos::plugins::uuid::Object_Id room_id) {
  Req_Chat_History req_chat_history(room_id, Client_Presenter::REQ_CHAT_HISTORY_COUNT);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_chat_history);
}
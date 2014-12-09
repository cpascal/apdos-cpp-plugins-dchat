#include "client_presenter.h"
#include <events/req_login.h>
#include <events/req_logout.h>
#include <events/req_add_room.h>
#include <events/req_join_room.h>

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

void Client_Presenter::add_room(std::string room_name) {
  Req_Add_Room req_add_room(room_name);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_add_room);
}

void Client_Presenter::join_room(apdos::plugins::uuid::Object_Id room_id) {
  Req_Join_Room req_join_room(room_id);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_join_room);
}

void Client_Presenter::leave_room() {
}

void Client_Presenter::user_chat(std::string message) {
}
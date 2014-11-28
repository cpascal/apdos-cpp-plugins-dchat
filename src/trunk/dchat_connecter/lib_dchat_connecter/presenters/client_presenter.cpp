#include "client_presenter.h"
#include <events/req_login.h>

using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::presenters;

void Client_Presenter::set_component(boost::shared_ptr<Actor_Connecter> actor_connecter) {
  this->actor_connecter = actor_connecter;
}

void Client_Presenter::login(std::string user_name) {
  Req_Login req_login(user_name);
  actor_connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_login);
}

void Client_Presenter::logout() {
}

void Client_Presenter::add_room(std::string room_name) {
}

void Client_Presenter::join_room(apdos::plugins::uuid::Object_Id room_id) {
}

void Client_Presenter::leave_room() {
}

void Client_Presenter::user_chat(std::string message) {
}
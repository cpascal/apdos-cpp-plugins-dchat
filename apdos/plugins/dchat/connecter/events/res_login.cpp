#include "res_login.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Login::RES_LOGIN = "res_login";

Res_Login::Res_Login(): Event("Res_Login", RES_LOGIN) {
}

std::string Res_Login::get_user_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Res_Login::get_user_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

Any_Vector_Shared_Ptr Res_Login::get_rooms() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<Any_Vector_Shared_Ptr>(map["rooms"]);
}

#include "res_logout.h"

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Logout::RES_LOGOUT = "res_logout";

Res_Logout::Res_Logout(): Event("Res_Logout", RES_LOGOUT) {
}

std::string Res_Logout::get_user_id() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Res_Logout::get_user_name() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}
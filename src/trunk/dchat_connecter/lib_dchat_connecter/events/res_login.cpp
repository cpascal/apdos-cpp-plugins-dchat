#include "res_login.h"

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Login::RES_LOGIN = "res_login";

Res_Login::Res_Login(std::string user_name): Event("Res_Login", RES_LOGIN) {
}

std::string Res_Login::get_user_id() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Res_Login::get_user_name() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

boost::shared_ptr<std::vector<boost::any>> Res_Login::get_rooms() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<boost::shared_ptr<std::vector<boost::any>>>(map["rooms"]);
}

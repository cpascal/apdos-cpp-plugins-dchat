#include "notify_logout.h"

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Notify_Logout::NOTIFY_LOGOUT = "notify_logout";

Notify_Logout::Notify_Logout(): Event("Notify_Logout", NOTIFY_LOGOUT) {
}

std::string Notify_Logout::get_user_id() {
  boost::shared_ptr<std::map<std::string, boost::any> > data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Notify_Logout::get_user_name() {
  boost::shared_ptr<std::map<std::string, boost::any> > data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}
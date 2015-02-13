#include "notify_user_chat.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Notify_User_Chat::NOTIFY_USER_CHAT = "notify_user_chat";

Notify_User_Chat::Notify_User_Chat(): Event("Notify_User_Chat", NOTIFY_USER_CHAT) {
}

std::string Notify_User_Chat::get_user_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Notify_User_Chat::get_user_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

std::string Notify_User_Chat::get_user_message() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_message"]);
}

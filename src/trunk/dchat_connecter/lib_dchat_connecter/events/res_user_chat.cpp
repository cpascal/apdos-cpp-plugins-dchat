#include "res_user_chat.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_User_Chat::RES_USER_CHAT = "res_user_chat";

Res_User_Chat::Res_User_Chat(): Event("Res_User_Chat", RES_USER_CHAT) {
}

std::string Res_User_Chat::get_user_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Res_User_Chat::get_user_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

std::string Res_User_Chat::get_user_message() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_message"]);
}

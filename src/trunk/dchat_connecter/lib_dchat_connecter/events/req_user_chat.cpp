#include "req_user_chat.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Req_User_Chat::REQ_USER_CHAT = "req_user_chat";

Req_User_Chat::Req_User_Chat(std::string message): Event("Req_User_Chat", REQ_USER_CHAT) {
  boost::shared_ptr<std::map<std::string, boost::any>> data(new std::map<std::string, boost::any>());
  data->insert(std::make_pair("message", boost::any(message)));
  this->set_data(data);
}
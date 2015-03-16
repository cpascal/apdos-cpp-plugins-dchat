#include "req_chat_history.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;
using namespace apdos::plugins::uuid;

const char* Req_Chat_History::REQ_CHAT_HISTORY = "req_chat_history";

Req_Chat_History::Req_Chat_History(Object_Id room_id, int chat_count): Event("Req_Chat_History", REQ_CHAT_HISTORY) {
  boost::shared_ptr<std::map<std::string, boost::any> > data(new std::map<std::string, boost::any>());
  data->insert(std::make_pair("room_id", boost::any(room_id.get_value())));
  data->insert(std::make_pair("chat_count", boost::any(chat_count)));
  this->set_data(data);
}
#include "proxy_event.h"

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor::events;

const char* Proxy_Event::PROXY_EVENT = "proxy_event";

Proxy_Event::Proxy_Event() {
}

Proxy_Event::Proxy_Event(std::string sender_path, std::string receiver_path, Event remote_event):
Event("Proxy_Event", PROXY_EVENT) {
  this->set_data(this->create_event_data(sender_path, receiver_path, remote_event));
}

boost::shared_ptr<std::map<const char*, boost::any>> Proxy_Event::create_event_data(
  std::string sender_path, 
  std::string receiver_path, 
  apdos::kernel::event::Event remote_event) {
    boost::shared_ptr<std::map<const char*, boost::any>> result(new std::map<const char*, boost::any>);
    std::map<const char*, boost::any>& map = *result.get();
    map["target_type"] = boost::any(remote_event.get_type());
    map["target_name"] = boost::any(remote_event.get_name());
    map["target_data"] = boost::any(remote_event.get_data());
    map["sender_path"] = boost::any(sender_path);
    map["receiver_path"] = boost::any(receiver_path);
    return result;
}

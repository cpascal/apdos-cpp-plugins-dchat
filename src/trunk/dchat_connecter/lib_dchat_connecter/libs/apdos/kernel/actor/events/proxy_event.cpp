#include "proxy_event.h"

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor::events;

const char* Proxy_Event::PROXY_EVENT = "proxy_event";

Proxy_Event::Proxy_Event(std::string sender_path, std::string receiver_path, Event remote_event) :
Event("Proxy_Event", PROXY_EVENT) {
  this->set_data(this->create_event_data(sender_path, receiver_path, remote_event));
}

std::map<const char*, boost::any> Proxy_Event::create_event_data(
  std::string sender_path, 
  std::string receiver_path, 
  apdos::kernel::event::Event remote_event) {
  std::map<const char*, boost::any> result;
  result["target_type"] = boost::any(remote_event.get_type());
  result["target_name"] = boost::any(remote_event.get_name());
  result["target_data"] = boost::any(remote_event.get_data());
  result["sender_path"] = boost::any(sender_path);
  result["receiver_path"] = boost::any(receiver_path);
  return result;
}

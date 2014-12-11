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

boost::shared_ptr<std::map<std::string, boost::any> > Proxy_Event::create_event_data(
  std::string sender_path, 
  std::string receiver_path, 
  apdos::kernel::event::Event remote_event) {
    boost::shared_ptr<std::map<std::string, boost::any> > result(new std::map<std::string, boost::any>);
    std::map<std::string, boost::any>& map = *result.get();
    map[std::string("target_type")] = boost::any(remote_event.get_type());
    map[std::string("target_name")] = boost::any(remote_event.get_name());
    map[std::string("target_data")] = boost::any(remote_event.get_data());
    map[std::string("sender_path")] = boost::any(sender_path);
    map[std::string("receiver_path")] = boost::any(receiver_path);
    return result;
}

std::string Proxy_Event::get_sender_path() {
  std::map<std::string, boost::any>& map = *this->data.get();
  return boost::any_cast<std::string>(map["sender_path"]);
}

std::string Proxy_Event::get_receiver_path() {
  std::map<std::string, boost::any>& map = *this->data.get();
  return boost::any_cast<std::string>(map["receiver_path"]);
}


std::string Proxy_Event::get_target_type() {
  std::map<std::string, boost::any>& map = *this->data.get();
  return boost::any_cast<std::string>(map["target_type"]);
}

std::string Proxy_Event::get_target_name() {
  std::map<std::string, boost::any>& map = *this->data.get();
  return boost::any_cast<std::string>(map["target_name"]);
}

boost::shared_ptr<std::map<std::string, boost::any> > Proxy_Event::get_target_data() {
  std::map<std::string, boost::any>& map = *this->data.get();
  return boost::any_cast<boost::shared_ptr<std::map<std::string, boost::any> > >(map["target_data"]);
}
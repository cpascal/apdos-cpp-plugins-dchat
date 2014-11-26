#include "event_dispatcher.h"

using namespace apdos::kernel::event;

Event_Dispatcher::Event_Dispatcher() {
}

Event_Dispatcher::~Event_Dispatcher() {
}

void Event_Dispatcher::add_event_listener(std::string event_name, const Event_Callback::slot_type& listener) {
  event_listeners[event_name].connect(listener);
}

void Event_Dispatcher::dispatch_event(Event& event) {
  if (event_listeners.find(event.get_name()) != event_listeners.end()) {
    event_listeners[event.get_name()](event);
  }
}

#ifndef APDOS_KERNEL_EVENT_EVENT_DISPATCHER_H
#define APDOS_KERNEL_EVENT_EVENT_DISPATCHER_H

#include <iostream>
#include <boost/signal.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include "event.h"

namespace apdos {
  namespace kernel {
    namespace event {
      class Event_Dispatcher {
        typedef boost::signal<void (Event& event)> Event_Callback;

      public:
        Event_Dispatcher();
        virtual ~Event_Dispatcher();

        void add_event_listener(std::string event_name, const Event_Callback::slot_type& listener);
        void dispatch_event(Event& event);

      private:
        boost::ptr_map<std::string, Event_Callback> event_listeners;
      };
    }
  }
}

#endif //APDOS_KERNEL_EVENT_EVENT_DISPATCHER_H
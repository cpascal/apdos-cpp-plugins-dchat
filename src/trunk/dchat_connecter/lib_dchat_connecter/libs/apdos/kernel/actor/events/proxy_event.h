#ifndef APDOS_KERNEL_ACTOR_EVENTS_PROXY_EVENT_H
#define APDOS_KERNEL_ACTOR_EVENTS_PROXY_EVENT_H

#include <iostream>
#include <map>
#include <libs/apdos/kernel/event/event.h>
#include <boost/shared_ptr.hpp>
#include <boost/any.hpp>

namespace apdos {
  namespace kernel {
    namespace actor {
      namespace events {
        class Proxy_Event: public apdos::kernel::event::Event {
        public:
          static const char* PROXY_EVENT;

        public:
          Proxy_Event();
          Proxy_Event(std::string sender_path, std::string receiver_path, apdos::kernel::event::Event remote_event);

          std::string get_sender_path();
          std::string get_receiver_path();

          std::string get_target_type();
          std::string get_target_name();
          boost::shared_ptr<std::map<std::string, boost::any> > get_target_data();

        private:
          boost::shared_ptr<std::map<std::string, boost::any> > create_event_data(
            std::string sender_path, 
            std::string receiver_path, 
            apdos::kernel::event::Event remote_event);
        };
      }
    }
  }
}

#endif //APDOS_KERNEL_ACTOR_EVENTS_PROXY_EVENT_H
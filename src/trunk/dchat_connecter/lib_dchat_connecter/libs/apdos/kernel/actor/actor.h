#ifndef APDOS_KERNEL_ACTOR_ACTOR_H
#define APDOS_KERNEL_ACTOR_ACTOR_H

#include <iostream>
#include <vector>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/event/event.h>
#include <libs/apdos/kernel/actor/component.h>
#include <boost/smart_ptr.hpp>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Actor {
      public:
        Actor(std::string path);
        virtual ~Actor();

        template <class T>
        boost::shared_ptr<T> add_component() {
          boost::shared_ptr<T> result(new T());
          this->components.push_back(result);
          return result;
        }

        void dispatch_event(apdos::kernel::event::Event& event);

        std::string get_path() { return this->path; }

      private:
        std::string path;
        std::vector<boost::shared_ptr<apdos::kernel::actor::Component>> components;
      };
    }
  }
}

#endif//APDOS_KERNEL_ACTOR_ACTOR_H
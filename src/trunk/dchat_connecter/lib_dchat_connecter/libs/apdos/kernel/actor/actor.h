#ifndef APDOS_KERNEL_ACTOR_ACTOR_H
#define APDOS_KERNEL_ACTOR_ACTOR_H

#include <iostream>
#include <vector>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/event/event.h>
#include <libs/apdos/kernel/root_node.h>
#include <boost/smart_ptr.hpp>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Actor: public apdos::kernel::Root_Node { 
      public:
        Actor(std::string path);
        virtual ~Actor();

        virtual bool is_null() { return false; }

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
        std::vector< boost::shared_ptr<apdos::kernel::actor::Component> > components;

      public:
        static boost::shared_ptr<Actor> lookup(std::string path);
      };
    }
  }
}

#endif//APDOS_KERNEL_ACTOR_ACTOR_H
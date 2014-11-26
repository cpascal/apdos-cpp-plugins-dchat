#ifndef APDOS_KERNEL_ACTOR_COMPONENT_H
#define APDOS_KERNEL_ACTOR_COMPONENT_H

#include <iostream>
#include <libs/apdos/kernel/event/event_dispatcher.h>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Component: public apdos::kernel::event::Event_Dispatcher {
      public:
        Component() {}
      };
    }
  }
}

#endif //APDOS_KERNEL_ACTOR_COMPONENT_H
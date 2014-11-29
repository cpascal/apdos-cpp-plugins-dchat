#ifndef APDOS_KERNEL_NODE_H
#define APDOS_KERNEL_NODE_H

#include <iostream>
#include <libs/apdos/kernel/event/event_dispatcher.h>

namespace apdos {
  namespace kernel {
      class Node: public apdos::kernel::event::Event_Dispatcher {
      public:
        Node() {}

        virtual bool is_null() = 0;
      };
    }
}

#endif //APDOS_KERNEL_NODE_H
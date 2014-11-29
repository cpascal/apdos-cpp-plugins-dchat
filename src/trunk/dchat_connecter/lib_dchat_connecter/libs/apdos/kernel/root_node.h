#ifndef APDOS_KERNEL_ROOT_NODE_H
#define APDOS_KERNEL_ROOT_NODE_H

#include <iostream>
#include <libs/apdos/kernel/node.h>

namespace apdos {
  namespace kernel {
      class Root_Node: public apdos::kernel::Node {
      public:
        Root_Node() {}

        virtual bool is_null() {
          return false;
        }
      };
    }
}

#endif //APDOS_KERNEL_ROOT_NODE_H
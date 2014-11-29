#ifndef APDOS_KERNEL_NULL_NODE_H
#define APDOS_KERNEL_NULL_NODE_H

#include <iostream>
#include <libs/apdos/kernel/node.h>

namespace apdos {
  namespace kernel {
      class Null_Node: public apdos::kernel::Node {
      public:
        Null_Node() {}

        virtual bool is_null() {
          return true;
        }
      };
    }
}

#endif //APDOS_KERNEL_NULL_NODE_H
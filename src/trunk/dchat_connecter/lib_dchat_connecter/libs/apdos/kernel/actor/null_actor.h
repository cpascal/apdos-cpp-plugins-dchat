#ifndef APDOS_KERNEL_ACTOR_NULL_ACTOR_H
#define APDOS_KERNEL_ACTOR_NULL_ACTOR_H

#include <iostream>
#include <vector>
#include <libs/apdos/kernel/actor/actor.h>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Null_Actor: public apdos::kernel::actor::Actor {
      public:
        Null_Actor(std::string path);
        virtual ~Null_Actor();

        virtual bool is_null() { return false; }
      };
    }
  }
}

#endif//APDOS_KERNEL_ACTOR_NULL_ACTOR_H
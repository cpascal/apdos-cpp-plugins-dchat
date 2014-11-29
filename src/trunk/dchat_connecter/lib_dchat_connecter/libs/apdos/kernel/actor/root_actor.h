#ifndef APDOS_KERNEL_ACTOR_ROOT_ACTOR_H
#define APDOS_KERNEL_ACTOR_ROOT_ACTOR_H

#include <iostream>
#include <vector>
#include <libs/apdos/kernel/actor/actor.h>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Root_Actor: public apdos::kernel::actor::Actor {
      public:
        Root_Actor(std::string path);
        virtual ~Root_Actor();

        virtual bool is_null() { return false; }
      };
    }
  }
}

#endif//APDOS_KERNEL_ACTOR_ROOT_ACTOR_H
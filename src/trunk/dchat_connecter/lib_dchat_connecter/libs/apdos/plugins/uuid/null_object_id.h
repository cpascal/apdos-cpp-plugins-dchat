#ifndef APDOS_PLUGINS_UUID_NULL_OBJECT_ID_H
#define APDOS_PLUGINS_UUID_NULL_OBJECT_ID_H

#include <iostream>
#include "object_id.h"

namespace apdos {
  namespace plugins {
    namespace uuid {
      class Null_Object_Id: public Object_Id {
      public:
        Null_Object_Id(): Object_Id("") {
        }

        virtual bool is_null() { return true; }
      };
    }
  }
}

#endif //APDOS_PLUGINS_UUID_NULL_OBJECT_ID_H
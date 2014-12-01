#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class Room {
        public:
          Room(apdos::plugins::uuid::Object_Id id, int num, std::string name);
          ~Room();

          apdos::plugins::uuid::Object_Id get_id();
          int get_num();
          std::string get_name();

        private:
          apdos::plugins::uuid::Object_Id id;
          int num;
          std::string name;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H
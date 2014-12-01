#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class User {
        public:
          User(apdos::plugins::uuid::Object_Id id, std::string name);

          apdos::plugins::uuid::Object_Id get_id();
          std::string get_name();

          void join_room(apdos::plugins::uuid::Object_Id room_id);
          void leave_room();

          apdos::plugins::uuid::Object_Id get_room_id();

        private:
          apdos::plugins::uuid::Object_Id id;
          std::string name;
          apdos::plugins::uuid::Object_Id room_id;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H
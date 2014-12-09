#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_USER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_USER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class Room_User {
        public:
          Room_User(apdos::plugins::uuid::Object_Id id, std::string name);

          virtual bool is_null() { return false; }

          apdos::plugins::uuid::Object_Id get_id();
          std::string get_name();

        private:
          apdos::plugins::uuid::Object_Id id;
          std::string name;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_USER_H
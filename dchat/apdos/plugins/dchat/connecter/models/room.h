#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class Room {
        public:
          Room(apdos::plugins::uuid::Object_Id id, int num, std::string name, int user_count, int max_user_count);
          ~Room();

          apdos::plugins::uuid::Object_Id get_id();
          int get_num();
          std::string get_name();
          int get_user_count();
          int get_max_user_count();

          void increase_user_count();
          void decrease_user_count();

          virtual bool is_null() { return false; }

        private:
          apdos::plugins::uuid::Object_Id id;
          int num;
          std::string name;
          int user_count;
          int max_user_count;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_ROOM_H
#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        typedef boost::shared_ptr<apdos::plugins::uuid::Object_Id> Object_Id_Shared_Ptr;

        class User {
        public:
          User(Object_Id_Shared_Ptr id, std::string name);

          virtual bool is_null() { return false; }

          Object_Id_Shared_Ptr get_id();
          std::string get_name();

          void join_room(Object_Id_Shared_Ptr room_id);
          void leave_room();

          Object_Id_Shared_Ptr get_room_id();

        private:
          Object_Id_Shared_Ptr id;
          std::string name;
          Object_Id_Shared_Ptr room_id;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_USER_H
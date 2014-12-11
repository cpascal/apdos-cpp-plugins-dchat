#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_ROOM_USERS_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_ROOM_USERS_H

#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/plugins/uuid/object_id.h>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "room_user.h"

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        typedef std::vector<boost::shared_ptr<Room_User> > Room_User_Vector;
        typedef boost::shared_ptr<Room_User_Vector> Room_User_Vector_Shared_Ptr;

        class Room_Users: public apdos::kernel::actor::Component {
        public:
          Room_Users();

          void clear();
          void add_room_user(apdos::plugins::uuid::Object_Id room_user_id, std::string room_user_name);
          void remove_room_user(apdos::plugins::uuid::Object_Id room_user_id);

          Room_User_Vector_Shared_Ptr get_room_users() { return this->room_users; }

        private:

        private:
          Room_User_Vector_Shared_Ptr room_users;
        };
      }
    }
  }
}

#endif//APDOS_PLUGINS_DCHAT_CONNECTER_ROOM_USERS_H
  

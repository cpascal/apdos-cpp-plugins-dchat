#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_ROOMS_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_ROOMS_H

#include <apdos/kernel/actor/component.h>
#include <apdos/plugins/uuid/object_id.h>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "room.h"

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        typedef boost::shared_ptr<Room> Room_Shared_Ptr;
        typedef std::vector<Room_Shared_Ptr > Room_Vector;
        typedef boost::shared_ptr<Room_Vector > Room_List_Shared_Ptr;

        class Rooms: public apdos::kernel::actor::Component {
        public:
          Rooms();

          void clear();
          void add_room(apdos::plugins::uuid::Object_Id room_id, std::string room_name, int user_count, int max_user_count);

          Room_List_Shared_Ptr get_rooms();
          Room_Shared_Ptr find_room_by_id(apdos::plugins::uuid::Object_Id  &room_id);

        private:
          int gen_room_num();

        private:
          boost::shared_ptr<std::vector<boost::shared_ptr<Room> > > rooms;
          int increment_count;
        };
      }
    }
  }
}

#endif//APDOS_PLUGINS_DCHAT_CONNECTER_ROOMS_H
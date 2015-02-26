#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/actor/actor_connecter.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace presenters {
        typedef boost::shared_ptr<apdos::kernel::actor::Actor_Connecter> Actor_Connecter_Shared_Ptr;

        class Client_Presenter: public apdos::kernel::actor::Component {
        public:
          void set_component(Actor_Connecter_Shared_Ptr actor_connecter);

          void login(std::string user_name);
          void logout();
          void add_room(std::string room_name);
          void join_room(apdos::plugins::uuid::Object_Id room_id);
          void leave_room();
          void user_chat(std::string message);

        private:
          Actor_Connecter_Shared_Ptr actor_connecter;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
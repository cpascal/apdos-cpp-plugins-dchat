#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/actor/connecters/actor_connecter.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace presenters {
        typedef boost::shared_ptr<apdos::kernel::actor::connecters::Actor_Connecter> Actor_Connecter_Shared_Ptr;

        class Client_Presenter: public apdos::kernel::actor::Component {
        public:
          static const int REQ_CHAT_HISTORY_COUNT = 3;

        public:
          void set_component(Actor_Connecter_Shared_Ptr actor_connecter);

          void login(std::string user_name);
          void logout();
          void add_room(std::string room_type, std::string room_name);
          void join_room(apdos::plugins::uuid::Object_Id room_id);
          void leave_room();
          void user_chat(std::string message);
          void chat_history(apdos::plugins::uuid::Object_Id room_id);

        private:
          Actor_Connecter_Shared_Ptr actor_connecter;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
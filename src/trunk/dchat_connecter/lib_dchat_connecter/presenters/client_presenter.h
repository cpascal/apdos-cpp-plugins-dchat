#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/actor/actor_connecter.h>
#include <libs/apdos/plugins/uuid/object_id.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace presenters {
        class Client_Presenter: public apdos::kernel::actor::Component {
        public:
          void set_component(boost::shared_ptr<apdos::kernel::actor::Actor_Connecter> actor_connecter);

          void login(std::string user_name);
          void logout();
          void add_room(std::string room_name);
          void join_room(apdos::plugins::uuid::Object_Id room_id);
          void leave_room();
          void user_chat(std::string message);

        private:
          boost::shared_ptr<apdos::kernel::actor::Actor_Connecter> actor_connecter;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_PRESENTER_H
#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/plugins/uuid/object_id.h>
#include <libs/apdos/kernel/event/event.h>
#include <models/auth.h>
#include <models/rooms.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace presenters {
        class Client_Listener_Presenter: public apdos::kernel::actor::Component {
        public:
          void set_component(boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> auth, boost::shared_ptr<apdos::plugins::dchat_connecter::models::Rooms> rooms);

        private:
          void on_res_login(apdos::kernel::event::Event& event);

          boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> auth;
          boost::shared_ptr<apdos::plugins::dchat_connecter::models::Rooms> rooms;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H
#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_WS_CCLIENT_PRESENTERS_CLIENT_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_WS_CCLIENT_PRESENTERS_CLIENT_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <apdos/kernel/actor/component.h>
#include <apdos/plugins/ws_net/ws_actor_connecter.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace presenters {
          typedef boost::shared_ptr<apdos::plugins::ws_net::Ws_Actor_Connecter> Ws_Actor_Connecter_Shared_Ptr;

          class Ws_Client_Presenter: public apdos::kernel::actor::Component {
          public:
            void start(const std::string host_address);

          private:
            void on_res_connected(apdos::kernel::event::Event& event);
            void on_res_disconnected(apdos::kernel::event::Event& event);
            void on_connect_failed(apdos::kernel::event::Event& event);

            void on_res_login(apdos::kernel::event::Event& event);
            void on_res_error(apdos::kernel::event::Event& event);

          private:
            Ws_Actor_Connecter_Shared_Ptr actor_connecter;
            std::string host_address;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_WS_CCLIENT_PRESENTERS_CLIENT_PRESENTER_H
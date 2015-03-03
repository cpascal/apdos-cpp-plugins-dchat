#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H

#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/event/event.h>
#include <apdos/plugins/ws_net/ws_actor_connecter.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace models {
          typedef boost::shared_ptr<apdos::plugins::ws_net::Ws_Actor_Connecter> Ws_Actor_Connecter_Shared_Ptr;

          class Line_Input: public apdos::kernel::actor::Component {
          public:
            Line_Input();
            virtual ~Line_Input();

            void set_component(Ws_Actor_Connecter_Shared_Ptr actor_connecter);

            /**
            * 유저의 입력을 받아들인다.
             */
            void poll();
            void stop();

          private:
            bool is_stop;
            Ws_Actor_Connecter_Shared_Ptr actor_connecter;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H
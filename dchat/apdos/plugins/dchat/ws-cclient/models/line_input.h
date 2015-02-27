#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H

#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/event/event.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace models {
          class Line_Input: public apdos::kernel::actor::Component {
          public:
            Line_Input();
            virtual ~Line_Input();

            /**
             * 유저의 입력을 받아들인다.
             */
            void poll();
            void stop();

          private:
            bool is_stop;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_MODELS_LINE_INPUT_H
#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_LINE_INPUT_EVENT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_LINE_INPUT_EVENT_H

#include <iostream>
#include <apdos/kernel/event/event.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace models {
          namespace events {
            class Line_Input_Event: public apdos::kernel::event::Event {
            public:
              static const char* LINE_INPUT_STRING;

            public:
              Line_Input_Event(std::string input_string);

              std::string get_line_input_string();
            };
          }
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H
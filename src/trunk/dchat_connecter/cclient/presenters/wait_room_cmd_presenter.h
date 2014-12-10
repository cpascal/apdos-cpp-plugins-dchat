#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H

#include <boost/asio.hpp>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/event/event.h>
#include "../models/line_input.h"
#include <presenters/client_presenter.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace presenters {
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::presenters::Client_Presenter> 
            Client_Presenter_Shared_Ptr;

          class Wait_Room_Cmd_Presenter: public apdos::kernel::actor::Component {
          public:
            Wait_Room_Cmd_Presenter();
            virtual ~Wait_Room_Cmd_Presenter();

            void set_components(Client_Presenter_Shared_Ptr client_presenter);

            void process_cmd(std::string line_input);

          private:
            Client_Presenter_Shared_Ptr client_presenter;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H
#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H

#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/event/event.h>
#include "../models/line_input.h"
#include <apdos/plugins/dchat/connecter/presenters/client_presenter.h>
#include <apdos/plugins/dchat/connecter/models/rooms.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace presenters {
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::presenters::Client_Presenter> 
            Client_Presenter_Shared_Ptr;
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::models::Rooms> Rooms_Shared_Ptr;

          class Wait_Room_Cmd_Presenter: public apdos::kernel::actor::Component {
          public:
            Wait_Room_Cmd_Presenter();
            virtual ~Wait_Room_Cmd_Presenter();

            void set_components(Client_Presenter_Shared_Ptr client_presenter, Rooms_Shared_Ptr rooms);

            void process_cmd(std::string line_input);

          private:
            void print_rooms();

          private:
            Client_Presenter_Shared_Ptr client_presenter;
            Rooms_Shared_Ptr rooms;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_WAIT_ROOM_CMD_PRESENTER_H
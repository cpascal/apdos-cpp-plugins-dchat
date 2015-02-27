#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H

#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/event/event.h>
#include "../models/line_input.h"
#include <apdos/plugins/dchat/connecter/presenters/client_presenter.h>
#include <apdos/plugins/dchat/connecter/models/auth.h>
#include "wait_room_cmd_presenter.h"
#include "chat_room_cmd_presenter.h"

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace cclient {
        namespace presenters {
          class Cmd_Presenter: public apdos::kernel::actor::Component {
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::models::Line_Input> Line_Input_Shared_Ptr;
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::presenters::Wait_Room_Cmd_Presenter>
            Wait_Room_Cmd_Presenter_Shared_Ptr;
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::presenters::Chat_Room_Cmd_Presenter>
            Chat_Room_Cmd_Presenter_Shared_Ptr;
          typedef boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> Auth_Shared_Ptr;

          public:
            Cmd_Presenter();
            virtual ~Cmd_Presenter();

            // @TODO 나중에 start이벤트 시작하면서 다른 컴포넌트 세팅하도록 변경. apdos-nodejs참고
            void set_components(
              Auth_Shared_Ptr auth,
              Line_Input_Shared_Ptr line_input, 
              Wait_Room_Cmd_Presenter_Shared_Ptr wait_room_cmd_presenter,
              Chat_Room_Cmd_Presenter_Shared_Ptr chat_room_cmd_presenter);

            void poll();

          private:
            void process_cmd(apdos::kernel::event::Event& event);

          private:
            Auth_Shared_Ptr auth;
            Line_Input_Shared_Ptr line_input;
            Wait_Room_Cmd_Presenter_Shared_Ptr wait_room_cmd_presenter;
            Chat_Room_Cmd_Presenter_Shared_Ptr chat_room_cmd_presenter;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H
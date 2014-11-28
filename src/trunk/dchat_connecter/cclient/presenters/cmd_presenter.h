#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H

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
          class Cmd_Presenter: public apdos::kernel::actor::Component {
          public:
            Cmd_Presenter();
            virtual ~Cmd_Presenter();

            // @TODO ���߿� start�̺�Ʈ �����ϸ鼭 �ٸ� ������Ʈ �����ϵ��� ����. apdos-nodejs����
            void set_components(boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::models::Line_Input> line_input, 
              boost::shared_ptr<apdos::plugins::dchat_connecter::presenters::Client_Presenter> client_presenter);

            void start();

          private:
            void process_cmd(apdos::kernel::event::Event& event);

          private:
            boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::models::Line_Input> line_input;
            boost::shared_ptr<apdos::plugins::dchat_connecter::presenters::Client_Presenter> client_presenter;
          };
        }
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_CCLIENT_PRESENTERS_CMD_PRESENTER_H
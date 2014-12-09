#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/plugins/uuid/object_id.h>
#include <libs/apdos/kernel/event/event.h>
#include <models/auth.h>
#include <models/rooms.h>
#include <presenters/client_presenter.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace presenters {
        typedef boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> Auth_Shared_Ptr;
        typedef boost::shared_ptr<apdos::plugins::dchat_connecter::models::Rooms> Rooms_Shared_Ptr;
        typedef boost::shared_ptr<apdos::plugins::dchat_connecter::presenters::Client_Presenter> 
          Client_Presenter_Shared_Ptr;

        class Client_Listener_Presenter: public apdos::kernel::actor::Component {
        public:
          void set_component(Auth_Shared_Ptr auth, Rooms_Shared_Ptr rooms, 
            Client_Presenter_Shared_Ptr client_presenter);

        private:
          void on_res_login(apdos::kernel::event::Event& event);
          void on_res_logout(apdos::kernel::event::Event& event);
          void on_res_add_room(apdos::kernel::event::Event& event);
          void on_notify_add_room(apdos::kernel::event::Event& event);
          void on_res_join_room(apdos::kernel::event::Event& event);
          void on_notify_join_room(apdos::kernel::event::Event& event);
          void on_res_leave_room(apdos::kernel::event::Event& event);
          void on_notify_leave_room(apdos::kernel::event::Event& event);
          void on_res_user_chat(apdos::kernel::event::Event& event);
          void on_notify_user_chat(apdos::kernel::event::Event& event);

          Auth_Shared_Ptr auth;
          Rooms_Shared_Ptr rooms;
          Client_Presenter_Shared_Ptr client_presenter;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_PRESENTERS_CLIENT_LISTENER_PRESENTER_H
#include "client_listener_presenter.h"
#include <iostream>
#include <boost/bind.hpp>
#include <events/res_login.h>

using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter;

void Client_Listener_Presenter::set_component(boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> auth) {
  this->auth = auth;

  this->add_event_listener(Res_Login::RES_LOGIN, boost::bind(&Client_Listener_Presenter::on_res_login, this, _1));
}

void Client_Listener_Presenter::on_res_login(apdos::kernel::event::Event& event) {
  Res_Login* e = (Res_Login*)&event;
  std::cout << e->get_name() << std::endl;  
}

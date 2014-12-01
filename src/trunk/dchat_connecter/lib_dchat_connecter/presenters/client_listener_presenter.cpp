#include "client_listener_presenter.h"
#include <iostream>
#include <boost/bind.hpp>
#include<libs/apdos/plugins/uuid/object_id.h>
#include <events/res_login.h>
#include <models/user.h>

using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter;

void Client_Listener_Presenter::set_component(boost::shared_ptr<apdos::plugins::dchat_connecter::models::Auth> auth,
  boost::shared_ptr<apdos::plugins::dchat_connecter::models::Rooms> rooms) {
  this->auth = auth;
  this->rooms = rooms;
  this->add_event_listener(Res_Login::RES_LOGIN, boost::bind(&Client_Listener_Presenter::on_res_login, this, _1));
}

void Client_Listener_Presenter::on_res_login(apdos::kernel::event::Event& event) {
  Res_Login* e = (Res_Login*)&event;
  std::cout << "login completed. user id: " << e->get_user_id() << ", name:" << e->get_user_name() << std::endl;  
  
  boost::shared_ptr<User> user(new User(Object_Id(e->get_user_id()), e->get_user_name()));
  auth->login(user);

  std::vector<boost::any>& rooms_data = *e->get_rooms().get();
  this->rooms->clear();
  for (int i = 0; i < rooms_data.size(); ++i) {
    boost::shared_ptr<std::map<std::string, boost::any>>& room = boost::any_cast<boost::shared_ptr<std::map<std::string, boost::any>>>(rooms_data[i]);
    std::map<std::string, boost::any>& map = *room.get();
    std:: cout << boost::any_cast<std::string>(map["id"]) << std::endl;
    std:: cout << boost::any_cast<std::string>(map["name"]) << std::endl;

    this->rooms->add_room(Object_Id(boost::any_cast<std::string>(map["id"])), boost::any_cast<std::string>(map["name"]));
  }

  std::cout << "rooms count: " << this->rooms->get_rooms()->size() << std::endl;
}

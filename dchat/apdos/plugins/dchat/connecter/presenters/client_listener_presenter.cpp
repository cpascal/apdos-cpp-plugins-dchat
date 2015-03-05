#include "client_listener_presenter.h"
#include <iostream>
#include <boost/bind.hpp>
#include <apdos/plugins/uuid/object_id.h>
#include <apdos/plugins/dchat/connecter/events/res_login.h>
#include <apdos/plugins/dchat/connecter/events/res_logout.h>
#include <apdos/plugins/dchat/connecter/events/res_add_room.h>
#include <apdos/plugins/dchat/connecter/events/notify_add_room.h>
#include <apdos/plugins/dchat/connecter/events/res_join_room.h>
#include <apdos/plugins/dchat/connecter/events/notify_join_room.h>
#include <apdos/plugins/dchat/connecter/events/res_leave_room.h>
#include <apdos/plugins/dchat/connecter/events/notify_leave_room.h>
#include <apdos/plugins/dchat/connecter/events/res_user_chat.h>
#include <apdos/plugins/dchat/connecter/events/notify_user_chat.h>
#include <apdos/plugins/dchat/connecter/models/user.h>

using namespace apdos::kernel::event;
using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter;

void Client_Listener_Presenter::set_component(Auth_Shared_Ptr auth, Rooms_Shared_Ptr rooms, 
  Room_Users_Shared_Ptr room_users, Client_Presenter_Shared_Ptr client_presenter) {
  this->auth = auth;
  this->rooms = rooms;
  this->room_users = room_users;
  this->client_presenter = client_presenter;

  this->add_event_listener(Res_Login::RES_LOGIN, boost::bind(&Client_Listener_Presenter::on_res_login, this, _1));
  this->add_event_listener(Res_Logout::RES_LOGOUT, boost::bind(&Client_Listener_Presenter::on_res_logout, this, _1));
  this->add_event_listener(Res_Add_Room::RES_ADD_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_res_add_room, this, _1));
  this->add_event_listener(Notify_Add_Room::NOTIFY_ADD_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_notify_add_room, this, _1));
  this->add_event_listener(Res_Join_Room::RES_JOIN_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_res_join_room, this, _1));
  this->add_event_listener(Notify_Join_Room::NOTIFY_JOIN_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_notify_join_room, this, _1));

  this->add_event_listener(Res_Leave_Room::RES_LEAVE_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_res_leave_room, this, _1));
  this->add_event_listener(Notify_Leave_Room::NOTIFY_LEAVE_ROOM, 
    boost::bind(&Client_Listener_Presenter::on_notify_leave_room, this, _1));
}

void Client_Listener_Presenter::on_res_login(apdos::kernel::event::Event& event) {
  Res_Login* e = (Res_Login*)&event;
  std::cout << "login completed. user id: " << e->get_user_id() << ", name:" << e->get_user_name() << std::endl;  
 
  boost::shared_ptr<Object_Id> user_id = boost::shared_ptr<Object_Id>(new Object_Id(e->get_user_id()));
  boost::shared_ptr<User> user(new User(user_id, e->get_user_name()));
  auth->login(user);

  // NDK에서는 const로 선언하지 않으면 컴파일 에러 발생
  const std::vector<boost::any>& rooms_data = *e->get_rooms().get();
  this->rooms->clear();
  for (int i = 0; i < rooms_data.size(); ++i) {
    // NDK에서는 const로 선언하지 않으면 컴파일 에러 발생
    const Any_Map_Shared_Ptr& room = boost::any_cast<Any_Map_Shared_Ptr >(rooms_data[i]);
    std::map<std::string, boost::any>& map = *room.get();
    this->rooms->add_room(Object_Id(boost::any_cast<std::string>(map["id"])), 
                          boost::any_cast<std::string>(map["name"]),
                          boost::any_cast<int>(map["user_count"]),
                          boost::any_cast<int>(map["max_user_count"]));
  }

  std::cout << "rooms count: " << this->rooms->get_rooms()->size() << std::endl;
}


void Client_Listener_Presenter::on_res_logout(apdos::kernel::event::Event& event) {
  Res_Logout* e = (Res_Logout*)&event;

  this->auth->logout();
  this->rooms->clear();
  std::cout << "logout completed. user name is " + e->get_user_name() << std::endl;
}

void Client_Listener_Presenter::on_res_add_room(apdos::kernel::event::Event& event) {
  Res_Add_Room* e = (Res_Add_Room*)&event;
  Object_Id room_id(e->get_room_id());
  this->rooms->add_room(room_id, e->get_room_name(), 0, e->get_room_max_user_count());
  std::cout << "add room id is " + e->get_room_id() << std::endl;
  this->client_presenter->join_room(room_id);
}


void Client_Listener_Presenter::on_notify_add_room(apdos::kernel::event::Event& event) {
  Notify_Add_Room* e = (Notify_Add_Room*)&event;

  this->rooms->add_room(Object_Id(e->get_room_id()), e->get_room_name(), 0, e->get_room_max_user_count());
  std::cout << "notify add room id is " + e->get_room_id() << std::endl;
}


void Client_Listener_Presenter::on_res_join_room(apdos::kernel::event::Event& event) {
  Res_Join_Room* e = (Res_Join_Room*)&event;
  std::cout << "res join room. user name: " + e->get_user_name() << std::endl;

  boost::shared_ptr<Object_Id> room_id(new Object_Id(e->get_room_id()));
  boost::shared_ptr<User> user = this->auth->get_login_user();
  // @TODO 현재 방에 들어 있는 유저정보를 불러와서 Room_Users의 정보를 갱신
  this->room_users->add_room_user(*user->get_id(), e->get_user_name());
  user->join_room(room_id);
  this->increase_user_count(*room_id.get());
}


void Client_Listener_Presenter::on_notify_join_room(apdos::kernel::event::Event& event) {
  Notify_Join_Room* e = (Notify_Join_Room*)&event;
  std::cout << "notify join room. user name: " + e->get_user_name() << std::endl;

  Object_Id room_id(e->get_room_id());
  Object_Id user_id(*this->auth->get_login_user()->get_id());
  if (*this->auth->get_login_user()->get_room_id().get() == room_id)
    this->room_users->add_room_user(user_id, e->get_user_name());
  this->increase_user_count(room_id);
}

void Client_Listener_Presenter::on_res_leave_room(apdos::kernel::event::Event& event) {
  Res_Leave_Room* e = (Res_Leave_Room*)&event;
  std::cout <<"res leave room. user name: " << e->get_user_name() << std::endl;

  this->room_users->clear();
  boost::shared_ptr<User> user = this->auth->get_login_user();
  user->leave_room();

  Object_Id room_id(e->get_room_id());
  this->decrease_user_count(room_id);
}

void Client_Listener_Presenter::on_notify_leave_room(apdos::kernel::event::Event& event) {
  Notify_Leave_Room* e = (Notify_Leave_Room*)&event;
  std::cout <<"notify leave room. user name: " << e->get_user_name() << std::endl;

  Object_Id user_id(e->get_user_id());
  Object_Id room_id(e->get_room_id());
  if (*this->auth->get_login_user()->get_room_id().get() == room_id)
    this->room_users->remove_room_user(user_id);
  this->decrease_user_count(room_id);
}

void Client_Listener_Presenter::on_res_user_chat(apdos::kernel::event::Event& event) {
  Res_User_Chat* e = (Res_User_Chat*)&event;
  std::cout << e->get_user_name() << " : " << e->get_user_message() << std::endl;
}

void Client_Listener_Presenter::on_notify_user_chat(apdos::kernel::event::Event& event) {
  Notify_User_Chat* e = (Notify_User_Chat*)&event;
  std::cout << e->get_user_name() << " : " << e->get_user_message() << std::endl;
}

void Client_Listener_Presenter::increase_user_count(Object_Id &room_id) {
  Room_Shared_Ptr room = this->rooms->find_room_by_id(room_id);
  if (room->is_null()) {
    std::cout << "Room is null." << std::endl;
    return;
  }
  room->increase_user_count();
}

void Client_Listener_Presenter::decrease_user_count(Object_Id &room_id) {
  Room_Shared_Ptr room = this->rooms->find_room_by_id(room_id);
  if (room->is_null()) {
    std::cout << "Room is null." << std::endl;
    return;
  }
  room->decrease_user_count();
}
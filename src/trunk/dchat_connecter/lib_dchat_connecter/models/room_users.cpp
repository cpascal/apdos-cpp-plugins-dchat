#include "room_users.h"

using namespace apdos::plugins::dchat_connecter::models;

Room_Users::Room_Users() {
  room_users = Room_User_Vector_Shared_Ptr(new Room_User_Vector());
}


void Room_Users::clear() {
  this->room_users->clear();
}

void Room_Users::add_room_user(apdos::plugins::uuid::Object_Id room_user_id, std::string room_user_name) {
  boost::shared_ptr<Room_User> room_user(new Room_User(room_user_id, room_user_name));
  this->room_users->push_back(room_user);
}


void Room_Users::remove_room_user(apdos::plugins::uuid::Object_Id room_user_id) {
  for (Room_User_Vector::iterator iter = room_users->begin(); iter != room_users->end(); ++iter) {
    if (room_user_id == iter->get()->get_id()) {
      this->room_users->erase(iter);
      break;
    }
  }
}

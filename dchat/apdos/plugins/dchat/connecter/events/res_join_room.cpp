#include "res_join_room.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Join_Room::RES_JOIN_ROOM = "res_join_room";

Res_Join_Room::Res_Join_Room(): Event("Res_Join_Room", RES_JOIN_ROOM) {
}

std::string Res_Join_Room::get_user_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Res_Join_Room::get_user_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

std::string Res_Join_Room::get_room_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_id"]);
}

std::string Res_Join_Room::get_room_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_name"]);
}

int Res_Join_Room::get_users_count() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<int>(map["users_count"]);
}
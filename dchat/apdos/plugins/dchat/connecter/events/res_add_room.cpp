#include "res_add_room.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Add_Room::RES_ADD_ROOM = "res_add_room";

Res_Add_Room::Res_Add_Room(): Event("Res_Add_Room", RES_ADD_ROOM) {
}

std::string Res_Add_Room::get_room_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_id"]);
}

std::string Res_Add_Room::get_room_type() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_type"]);
}

std::string Res_Add_Room::get_room_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_name"]);
}

int Res_Add_Room::get_room_max_user_count() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<int>(map["room_max_user_count"]);
}
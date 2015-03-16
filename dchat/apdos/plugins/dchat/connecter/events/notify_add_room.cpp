#include "notify_add_room.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Notify_Add_Room::NOTIFY_ADD_ROOM = "notify_add_room";

Notify_Add_Room::Notify_Add_Room(): Event("Notify_Add_Room", NOTIFY_ADD_ROOM) {
}

std::string Notify_Add_Room::get_room_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_id"]);
}

std::string Notify_Add_Room::get_room_type() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_type"]);
}

std::string Notify_Add_Room::get_room_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_name"]);
}

int Notify_Add_Room::get_room_max_user_count() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<int>(map["room_max_user_count"]);
}
#include "notify_leave_room.h"

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Notify_Leave_Room::NOTIFY_LEAVE_ROOM = "notify_leave_room";

Notify_Leave_Room::Notify_Leave_Room(): Event("Notify_Leave_Room", NOTIFY_LEAVE_ROOM) {
}

std::string Notify_Leave_Room::get_user_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_id"]);
}

std::string Notify_Leave_Room::get_user_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["user_name"]);
}

std::string Notify_Leave_Room::get_room_id() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_id"]);
}

std::string Notify_Leave_Room::get_room_name() {
  Any_Map_Shared_Ptr data = this->get_data();
  Any_Map& map = *data.get();
  return boost::any_cast<std::string>(map["room_name"]);
}
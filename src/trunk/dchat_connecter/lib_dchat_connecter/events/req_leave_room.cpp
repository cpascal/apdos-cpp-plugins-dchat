#include "req_leave_room.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;
using namespace apdos::plugins::uuid;

const char* Req_Leave_Room::REQ_LEAVE_ROOM = "req_leave_room";

Req_Leave_Room::Req_Leave_Room(): Event("Req_Leave_Room", REQ_LEAVE_ROOM) {
  
}
#include "null_room.h"
#include <apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::models;

Null_Room::Null_Room(): Room(Null_Object_Id(), 0, "", 0, 0) {
}

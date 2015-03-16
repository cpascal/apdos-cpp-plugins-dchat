#include "rooms.h"
#include <boost/shared_ptr.hpp>
#include <apdos/plugins/dchat/connecter/models/null_room.h>
#include <apdos/plugins/uuid/null_object_id.h>

using namespace boost;
using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::models;


Rooms::Rooms(): increment_count(0) {
  rooms = boost::shared_ptr<std::vector<boost::shared_ptr<Room> > >(new std::vector<boost::shared_ptr<Room> >());
}


boost::shared_ptr<std::vector<boost::shared_ptr<Room> > > Rooms::get_rooms() {
  return this->rooms;
}


void Rooms::clear() {
  this->rooms->clear();
}

void Rooms::add_room(apdos::plugins::uuid::Object_Id room_id, std::string room_type, std::string room_name, int user_count, int max_user_count) {
  boost::shared_ptr<Room> room(new Room(room_id, gen_room_num(), room_type, room_name, user_count, max_user_count));
  this->rooms->push_back(room);
}


Room_Shared_Ptr Rooms::find_room_by_id(Object_Id &room_id) {
  for (Room_Vector::iterator iter = rooms->begin(); iter != rooms->end(); ++iter) {
    if (iter->get()->get_id() == room_id) {
      return *iter;
    }
  }
  return boost::shared_ptr<Null_Room>(new Null_Room());
}

int Rooms::gen_room_num() {
  this->increment_count++;
  return increment_count;
}

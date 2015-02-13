#include "rooms.h"

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

void Rooms::add_room(apdos::plugins::uuid::Object_Id room_id, std::string room_name) {
  boost::shared_ptr<Room> room(new Room(room_id, gen_room_num(), room_name));
  this->rooms->push_back(room);
}

int Rooms::gen_room_num() {
  this->increment_count++;
  return increment_count;
}

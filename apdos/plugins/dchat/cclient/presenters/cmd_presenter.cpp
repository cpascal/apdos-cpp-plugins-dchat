#include "cmd_presenter.h"
#include <boost/bind.hpp>
#include "../models/events/line_input_event.h"
#include <events/res_login.h>
#include <models/user.h>

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;
using namespace apdos::plugins::dchat_connecter::models;

Cmd_Presenter::Cmd_Presenter() {
}


Cmd_Presenter::~Cmd_Presenter() {
}

void Cmd_Presenter::set_components(Auth_Shared_Ptr auth,
  Line_Input_Shared_Ptr line_input,
  Wait_Room_Cmd_Presenter_Shared_Ptr wait_room_cmd_presenter,
  Chat_Room_Cmd_Presenter_Shared_Ptr chat_room_cmd_presenter) {
  this->auth = auth;
  this->line_input = line_input;
  this->wait_room_cmd_presenter = wait_room_cmd_presenter;
  this->chat_room_cmd_presenter = chat_room_cmd_presenter;
  line_input->add_event_listener(Line_Input_Event::LINE_INPUT_STRING, 
    boost::bind(&Cmd_Presenter::process_cmd, this, _1));
}

void Cmd_Presenter::poll() {
  line_input->poll();
}

void Cmd_Presenter::process_cmd(Event& event) {
  Line_Input_Event* e = (Line_Input_Event*)&event;
  std::string line_input_string = e->get_line_input_string();
  std::cout << "Cmd_Presenter::process_cmd:" << line_input_string << std::endl;

  if (0 == line_input_string.compare("exit")) {
    line_input->stop();
  }
  boost::shared_ptr<User> user = this->auth->get_login_user();
  if (user->is_null())
    this->wait_room_cmd_presenter->process_cmd(line_input_string);
  else if (user->get_room_id()->is_null())
    this->wait_room_cmd_presenter->process_cmd(line_input_string);
  else
    this->chat_room_cmd_presenter->process_cmd(line_input_string);
}

#include "cmd_presenter.h"
#include <boost/bind.hpp>
#include "../models/events/line_input_event.h"
#include <events/res_login.h>

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;

Cmd_Presenter::Cmd_Presenter() {
}


Cmd_Presenter::~Cmd_Presenter() {
}

void Cmd_Presenter::set_components(boost::shared_ptr<Line_Input> line_input, 
  boost::shared_ptr<Client_Presenter> client_presenter) {
  this->line_input = line_input;
  this->client_presenter = client_presenter;
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
  if (0 == line_input_string.compare("login")) {
    std::string user_name = "test";
    client_presenter->login(user_name);
  }
  if (0 == line_input_string.compare("add_room")) {
    std::string room_name = "test_room";
    client_presenter->add_room(room_name);
  }
  if (0 == line_input_string.compare("logout")) {
    client_presenter->logout();
  }
}

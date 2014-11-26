#include "cmd_presenter.h"
#include "../models/events/line_input_event.h"
#include <boost/bind.hpp>

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;

Cmd_Presenter::Cmd_Presenter() {
}


Cmd_Presenter::~Cmd_Presenter() {
}

void Cmd_Presenter::set_line_input(boost::shared_ptr<apdos::plugins::dchat_connecter::cclient::models::Line_Input> line_input) {
  this->line_input = line_input;
}

void Cmd_Presenter::start() {
  line_input->add_event_listener(Line_Input_Event::LINE_INPUT_STRING, boost::bind(&Cmd_Presenter::process_cmd, this, _1));
  line_input->poll();
}

void Cmd_Presenter::process_cmd(Event& event) {
  Line_Input_Event* e = (Line_Input_Event*)&event;
  std::string line_input_string = e->get_line_input_string();
  std::cout << "Cmd_Presenter::process_cmd:" << line_input_string << std::endl;
  if (0 == line_input_string.compare("exit")) {
    line_input->stop();
  }
  /*
  if (0 == buffer.compare("login")) {
      //Req_Login req_login("test");
      //connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_login);
    }
  */
}

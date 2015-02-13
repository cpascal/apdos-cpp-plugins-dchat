#include "line_input.h"
#include "events/line_input_event.h"
#include <boost/bind.hpp>

using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;

Line_Input::Line_Input() {
}

Line_Input::~Line_Input() {
}


void Line_Input::poll() {
  is_stop = false;
  std::string buffer;	
  while (std::getline(std::cin, buffer)) {
    Line_Input_Event e(buffer);
    this->dispatch_event(e); 
    if (is_stop)
      break;
  }
}

void Line_Input::stop() {
  is_stop = true;
}

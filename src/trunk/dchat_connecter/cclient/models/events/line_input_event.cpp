#include "line_input_event.h"

using namespace apdos::plugins::dchat_connecter::cclient::models::events;
using namespace apdos::kernel::event;

const char* Line_Input_Event::LINE_INPUT_STRING = "line_input_string";

Line_Input_Event::Line_Input_Event(std::string input_string): 
Event("Lint_Input_Event", LINE_INPUT_STRING) {
  boost::shared_ptr<std::map<std::string, boost::any>> data(new std::map<std::string, boost::any>());
  data->insert(std::make_pair("line_input_string", boost::any(input_string)));
  this->set_data(data);
}

std::string Line_Input_Event::get_line_input_string() {
  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  std::map<std::string, boost::any>& d = *data.get();
  return boost::any_cast<std::string>(d["line_input_string"]);
}
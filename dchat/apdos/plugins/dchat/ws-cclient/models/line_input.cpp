#include "line_input.h"
#include "events/line_input_event.h"
#include <boost/bind.hpp>
#include <CCDirector.h>
#include <boost/thread.hpp>
#include <boost/lockfree/spsc_queue.hpp>

boost::lockfree::spsc_queue<std::string> commands(100);

struct InputServer {
  void operator() () {
    std::string command;
    while(std::getline(std::cin, command)) {
      commands.push(command);
    }
  }
};


using namespace apdos::kernel::event;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;
using namespace cocos2d;

Line_Input::Line_Input() {
}

Line_Input::~Line_Input() {
}


void Line_Input::poll() {
  is_stop = false;
  std::string buffer;
  InputServer input;
  boost::thread inputThread(input);

  while(1) {
    CCDirector::sharedDirector()->mainLoop();
    if (is_stop)
      break;
    if (commands.pop(buffer)) {
      Line_Input_Event e(buffer);
      this->dispatch_event(e); 
    }
  }
}

void Line_Input::stop() {
  is_stop = true;
}

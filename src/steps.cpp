#include "mint/steps.hpp"
#include "mint/state.hpp"
#include "mint/palette.hpp"

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

#include <boost/sml.hpp>
namespace sml = boost::sml;



Steps::Steps() {
};

void Steps::start() {
    state_machine.process_event(SetTextEvent{State::greeting});
}

void Steps::processKey(KeyEvent event) {
    state_machine.process_event(KeyPressedEvent{event});
}

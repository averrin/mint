#include "mint/steps.hpp"
#include "mint/state.hpp"

#include <boost/sml.hpp>
namespace sml = boost::sml;

Steps::Steps() {
};

void Steps::start() {

    std::string greeting = 
            "<tt>"
				"sample text for <span foreground='#3EB489'><b>mint</b></span><br>"
				"[<span underline='single'>link</span>] [<b>a</b>]"
            "</tt><br>"

            "<span font='FiraCode Medium 12'>"
				"sample text for <span foreground='#3EB489'><b>mint</b></span><br>"
				"[<span underline='single'>link</span>] [<b>a</b>]"
            "</span>";

    state_machine.process_event(SetTextEvent{greeting});
}




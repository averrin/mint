#ifndef __STEPS_H_
#define __STEPS_H_
#include <memory>
#include <iostream>

#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

#include "mint/state.hpp"
#include "mint/actions.hpp"

#include <boost/sml.hpp>
namespace sml = boost::sml;

struct events {
    auto operator()() const noexcept {
        using namespace sml;
        auto is_enter = [](KeyPressedEvent e) { return e.key.getCode() == KeyEvent::KEY_RETURN; };
        auto set_text = [] (std::shared_ptr<State> state, const SetTextEvent& e) {
            state->text = e.text;
        };
        auto step_one = [] (std::shared_ptr<State> state, const KeyPressedEvent& e) {
            state->text += State::step_one;
        };

        // clang-format off
        return make_transition_table(
            *"init"_s + event<SetTextEvent> / set_text  = "started"_s
            , "started"_s + event<KeyPressedEvent> [is_enter] / step_one  = "step_one"_s
        );
        // clang-format on
    }
};

class Steps {
public:
    std::shared_ptr<State> state = std::make_shared<State>();
    Steps();

    void processKey(KeyEvent e);
    void start();

private:
    sml::sm<events> state_machine = sml::sm<events>(state);
};


#endif // __STEPS_H_

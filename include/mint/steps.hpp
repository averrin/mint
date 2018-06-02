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
        auto set_text = [] (std::shared_ptr<State> state, const SetContentEvent& e) {
            state->fragments = e.content;
        };
        auto add_text = [] (std::shared_ptr<State> state, const AddContentEvent& e) {
            state->fragments.insert(state->fragments.end(), e.content.begin(), e.content.end());
        };
        auto step_one = [] (std::shared_ptr<State> state, const KeyPressedEvent& e) {
            state->fragments.insert(state->fragments.end(), State::step_one.begin(), State::step_one.end());
        };

        // clang-format off
        return make_transition_table(
            *"init"_s + event<SetContentEvent> / set_text  = "started"_s
            , "started"_s + event<AddContentEvent> / add_text  = "started"_s
            , "started"_s + event<KeyPressedEvent> [is_enter] / step_one  = "step_one"_s
            , "step_one"_s + event<AddContentEvent> / add_text  = "step_one"_s
        );
        // clang-format on
    }
};

class Steps {
public:
    std::shared_ptr<State> state = std::make_shared<State>();
    Steps();

    void processKey(KeyEvent e);
    void processMouse(MouseEvent event);
    void start();

private:
    sml::sm<events> state_machine = sml::sm<events>(state);
};


#endif // __STEPS_H_

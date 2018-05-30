#ifndef __STEPS_H_
#define __STEPS_H_
#include <memory>
#include <iostream>

#include "mint/state.hpp"
#include "mint/actions.hpp"

#include <boost/sml.hpp>
namespace sml = boost::sml;

struct events {
  auto operator()() const noexcept {
    using namespace sml;
    // auto guard = [](const SetTextEvent& e) { return e.text; };
    auto set_text = [] (std::shared_ptr<State> state, const SetTextEvent& e) {
        state->text = e.text;
    };
    auto init_state = "init"_s;

    // clang-format off
    return make_transition_table(
        *init_state + event<SetTextEvent> / set_text  = "started"_s
      // , "s1"_s + event2 [guard] = "s2"_s
      // , "s2"_s + "e3"_e = "s3"_s
      // , "s3"_s + event<e4> / [] (const auto& e) { assert(42 == e.value); } = X
    );
    // clang-format on
  }
};

class Steps {
public:
    std::shared_ptr<State> state = std::make_shared<State>();
    Steps();

    void start();

private:
    sml::sm<events> state_machine = sml::sm<events>(state);
};


#endif // __STEPS_H_

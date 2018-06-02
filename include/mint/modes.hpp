#ifndef __MODES_H_
#define __MODES_H_
#include <memory>

#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

#include <boost/sml.hpp>
namespace sml = boost::sml;

#include "mint/actions.hpp"

struct Modes {
    bool isNormal = true;
    bool isHints = false;
    bool isLeader = false;
};

struct modes {
    auto operator()() const noexcept {
        using namespace sml;
        auto is_hints = [](KeyPressedEvent e) { return e.key.getCode() == KeyEvent::KEY_f; };
        auto is_leader = [](KeyPressedEvent e) { return e.key.getCode() == KeyEvent::KEY_SPACE; };
        auto is_esc = [](KeyPressedEvent e) { return e.key.getCode() == KeyEvent::KEY_ESCAPE; };

        auto set_hints = [](std::shared_ptr<Modes> m) {
            std::cout << "Set HINTS mode" << std::endl;
            m->isNormal = false;
            m->isHints = true;
            m->isLeader = false;
        };
        auto set_leader = [](std::shared_ptr<Modes> m) {
            std::cout << "Set LEADER mode" << std::endl;
            m->isNormal = false;
            m->isHints = false;
            m->isLeader = true;
        };
        auto set_normal = [](std::shared_ptr<Modes> m) {
            std::cout << "Set NORMAL mode" << std::endl;
            m->isNormal = true;
            m->isHints = false;
            m->isLeader = false;
        };

        // clang-format off
        return make_transition_table(
            *"normal"_s + event<KeyPressedEvent> [is_hints] / set_hints  = "hints"_s
            , "normal"_s + event<KeyPressedEvent> [is_leader] / set_leader  = "leader"_s
            , "hints"_s + event<KeyPressedEvent> [is_esc] / set_normal = "normal"_s
            , "leader"_s + event<KeyPressedEvent> [is_esc] / set_normal  = "normal"_s
        );
        // clang-format on
    }
};

class ModeManager {
public:
    ModeManager();
    void processKey(KeyEvent e);
    std::shared_ptr<Modes> modeFlags = std::make_shared<Modes>();

private:
    sml::sm<modes> state_machine = sml::sm<modes>(modeFlags);
};


class Mode {
public:
    Mode();
    void processKey(KeyEvent e);
};

class HintsMode: public Mode {};
class NormalMode: public Mode {};
class LeaderMode: public Mode {};

#endif // __MODES_H_

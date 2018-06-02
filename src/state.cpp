#include "mint/state.hpp"
#include "mint/actions.hpp"
#include "Jinja2CppLight.h"

using namespace Jinja2CppLight;
using namespace std::string_literals;

std::string State::render() {
    std::string content;
    for (auto f : fragments) {
        content += f.render(*this);
    }
    return content;
};

std::string State::renderStatus() {
    std::string content;
    for (auto f : statusFragments) {
        content += f.render(*this);
    }
    // std::cout << content << std::endl;
    return content;
};

const std::string State::LINK = "[ <span underline='single' weight='bold'>{{title}}</span> ]";

const Fragments State::greeting = {{ 
    "I love <tt>text</tt>. Really.<br>"
    "But most of modern software tends to decrease text importance. "
    "They use a lot of colorful images and 'sexy' ui controls. Bleh.<br>"
    "So I create Mint."
    " <span color='{{green}}' weight='bold'>M</span>int"
    " <span color='{{green}}' weight='bold'>I</span>s"
    " <span color='{{green}}' weight='bold'>N</span>ot"
    " <span color='{{green}}' weight='bold'>T</span>erminal."
    " Because who needs terminal which cannot run Emacs?<br>"
    "Mint is bunch of text-based ui experiments. Mint is about text, keyboard and some oldschool habits. <br>" 
    "Press <b>Enter</b>…<br>"s}}
;

const Fragments State::step_one = {
    Fragment{"<br>Let`s begin!<br>"
    "What you prefer? "s},
    Link("Dark theme"s, ChangePaletteEvent(palettes::DARK)),
    {" or "s},
    Link("Light theme"s, ChangePaletteEvent(palettes::LIGHT)),
    {"?"s},
    };


const Fragments State::warn_mouse = {{ 
        "<br><br><span color='{{red}}' weight='bold'>Oops!</span> You cannot use mouse. I am so sorry;)<br><br>"
}};

const Fragments State::normal_mode = {{ "<span>NORMAL</span>" }};
const Fragments State::hints_mode = {{ "<span color='{{green}}'>HINTS</span>" }};
const Fragments State::leader_mode = {{ "<span color='{{blue}}'>LEADER</span>" }};

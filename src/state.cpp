#include "mint/state.hpp"
#include "Jinja2CppLight.h"

using namespace Jinja2CppLight;

std::string State::render() {
    Template tpl( text );
    tpl.setValue( "green", currentPalette.green);
    return tpl.render();
};


const std::string State::greeting = 
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
    "Press <b>Enter</b>…<br>"
;

const std::string State::step_one =
    "<br>Let`s begin!<br>"
    "What you prefer? [ <span underline='single' weight='bold'>Dark theme</span> ]"
    " or [ <span underline='single' weight='bold'>Light theme</span> ]?"
;

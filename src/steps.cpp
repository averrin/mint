#include "mint/steps.hpp"
#include "mint/state.hpp"
#include "mint/palette.hpp"

#include "cinder/gl/gl.h"

#include <boost/sml.hpp>
namespace sml = boost::sml;

Steps::Steps() {
    auto darkPalette = Palette{
        ci::Color(0xcc/255.f, 0xcc/255.f, 0xcc/255.f),
        ci::Color(0x11/255.f, 0x11/255.f, 0x11/255.f)};

    auto lightPalette = Palette{
        ci::Color(0x11/255.f, 0x11/255.f, 0x11/255.f),
        ci::Color(0xcc/255.f, 0xcc/255.f, 0xcc/255.f)};
    state->currentPalette = darkPalette;
};

void Steps::start() {

    std::string greeting = 
        "I love <tt>text</tt>. Really.<br>"
        "But most of modern software tends to decrease text importance. "
        "They use a lot of colorful images and 'sexy' ui controls. Bleh.<br>"
        "So I create Mint. <b>M</b>int <b>I</b>s <b>N</b>ot <b>T</b>erminal. Because who needs terminal which cannot run Emacs?<br>"
        "Mint is bunch of text-based ui experiments. Mint is about text, keyboard and some oldschool habits."
    ;

    state_machine.process_event(SetTextEvent{greeting});
}




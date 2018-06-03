#include "mint/state.hpp"
#include "mint/actions.hpp"
#include "Jinja2CppLight.h"

using namespace Jinja2CppLight;
using namespace std::string_literals;


void State::setContent(Fragments content) {
    fragments = content;
    damaged = true;
};

void State::appendContent(Fragments content) {
    fragments.insert(fragments.end(), content.begin(), content.end());
    damaged = true;
};

void State::render(kp::pango::CinderPangoRef surface) {
    std::string DEFAULT_FONT = "FiraCode 12";

    surface->setDefaultTextFont(DEFAULT_FONT);

    if (!damaged) {
        surface->setText(cache);
        surface->render();
        return;
    }

    std::string content;
    auto n = 0;
    for (auto f : fragments) {
        content += f->render(*this);
        surface->setText(content);
        surface->render();
        f->index = n;
        auto c = surface->getCount();
        f->length = c - n + 1;
        f->rect = surface->getRect(f->index, f->length);
        n = c + 2;
    }
    cache = content;

    damaged = false;
};

std::string State::renderStatus() {
    std::string content;
    for (auto f : statusFragments) {
        content += f->render(*this);
    }
    // std::cout << content << std::endl;
    return content;
};

//TODO: add active state with double underline
const std::string State::LINK = "[ <span underline='single' weight='bold'>{{title}}</span> ]";

const std::string State::LOADER = "<span weight='bold'>{{char}} {{title}}</span>";

auto F = [](std::string c) { return std::make_shared<Fragment>(c); };
auto Lo = [](std::string c) { return std::make_shared<Loader>(c); };
auto L = [](std::string t, std::shared_ptr<MintEvent> cb) { return std::make_shared<Link>(t, cb); };

const Fragments State::greeting = {F( 
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
    "Press <b>Enter</b> (or <b>Ctrl+J</b>, of course)…"s), F("<br>")}
;

const Fragments State::step_one = {
    F("<br>"),
    F("Let`s begin!"),
    F("<br>"),
    F("What you prefer? "s),
    L("Dark theme"s, std::make_shared<ChangePaletteEvent>(palettes::DARK)),
    F(" or "s),
    L("Light theme"s, std::make_shared<ChangePaletteEvent>(palettes::LIGHT)),
    F("?"s),
    F("<br>"),
    Lo("Waiting…")
    };


const Fragments State::warn_mouse = {
        F("<br><br><span color='{{red}}' weight='bold'>Oops!</span> You cannot use mouse. I am so sorry;)<br><br>")
};

const Fragments State::normal_mode = {F("<span>NORMAL</span>" )};
const Fragments State::hints_mode =  {F("<span color='{{green}}'>HINTS</span>" )};
const Fragments State::leader_mode = {F("<span color='{{blue}}'>LEADER</span>" )};

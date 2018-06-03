#ifndef __ACTIONS_H_
#define __ACTIONS_H_
#include <string>
#include "cinder/app/App.h"
#include "mint/palette.hpp"
#include "mint/fragment.hpp"

using namespace ci;
using namespace ci::app;

struct SetContentEvent : MintEvent {
    Fragments content;
    SetContentEvent(Fragments c) : MintEvent(), content(c) {};
};

struct AddContentEvent : MintEvent {
    Fragments content;
    AddContentEvent(Fragments c) : MintEvent(), content(c) {};
};


struct KeyPressedEvent : MintEvent {
    KeyEvent key;
    KeyPressedEvent(KeyEvent k) : MintEvent(), key(k) {};
};

struct ChangePaletteEvent : MintEvent {
    Palette palette;
    ChangePaletteEvent(Palette p) : MintEvent(), palette(p) {};
};

struct ModeExitedEvent : MintEvent {
    ModeExitedEvent() : MintEvent() {};
};

#endif // __ACTIONS_H_

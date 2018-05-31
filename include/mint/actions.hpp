#ifndef __ACTIONS_H_
#define __ACTIONS_H_
#include <string>
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

struct SetTextEvent {
    std::string text;
};

struct KeyPressedEvent {
    KeyEvent key;
};


#endif // __ACTIONS_H_

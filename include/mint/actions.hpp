#ifndef __ACTIONS_H_
#define __ACTIONS_H_
#include <string>
#include "cinder/app/App.h"
#include "mint/fragment.hpp"

using namespace ci;
using namespace ci::app;

struct SetContentEvent {
    Fragments content;
};

struct AddContentEvent {
    Fragments content;
};


struct KeyPressedEvent {
    KeyEvent key;
};


#endif // __ACTIONS_H_

#ifndef __STATE_H_
#define __STATE_H_
#include <string>
#include "mint/palette.hpp"

class State {
public:
    std::string text;
    Palette currentPalette;

    static const std::string greeting;
    static const std::string step_one;
};


#endif // __STATE_H_

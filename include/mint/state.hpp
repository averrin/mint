#ifndef __STATE_H_
#define __STATE_H_
#include <string>
#include <vector>
#include "mint/palette.hpp"
#include "mint/fragment.hpp"

class State {
public:
    Palette currentPalette;
    std::string render();
    std::string renderStatus();

    Fragments fragments;
    Fragments statusFragments;

    static const Fragments greeting;
    static const Fragments step_one;
    static const Fragments warn_mouse;
    static const Fragments welcome_hints;

    static const Fragments normal_mode;
    static const Fragments hints_mode;
    static const Fragments leader_mode;

    static const std::string LINK;

    bool mouseWarned = false;
};


#endif // __STATE_H_

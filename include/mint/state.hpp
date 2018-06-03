#ifndef __STATE_H_
#define __STATE_H_
#include <string>
#include <vector>
#include "mint/palette.hpp"
#include "mint/fragment.hpp"
#include "CinderPango.h"

class State {
public:
    Palette currentPalette;
    void render(kp::pango::CinderPangoRef);
    std::string renderStatus();

    void setContent(Fragments);
    void appendContent(Fragments);

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
    static const std::string LOADER;

    bool mouseWarned = false;

private:
    bool damaged = true;
    std::string cache;
};


#endif // __STATE_H_

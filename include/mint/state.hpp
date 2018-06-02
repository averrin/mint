#ifndef __STATE_H_
#define __STATE_H_
#include <string>
#include <vector>
#include "mint/palette.hpp"
#include "mint/fragment.hpp"

typedef std::vector<Fragment> Fragments;

class State {
public:
    Palette currentPalette;
    std::string render();

    Fragments fragments;

    static const Fragments greeting;
    static const Fragments step_one;

    static const std::string LINK;
};


#endif // __STATE_H_

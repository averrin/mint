#pragma once
#ifndef __PALETTE_H_
#define __PALETTE_H_
#include <string>
#include "cinder/gl/gl.h"

struct Palette {
    std::string name;
    ci::Color fgColor;
    ci::Color bgColor;
    ci::Color bgColorAlt;

    std::string green;
    std::string red;
    std::string blue;
};

class palettes {
public:
    static const Palette DARK;
    static const Palette LIGHT;
};

#endif // __PALETTE_H_

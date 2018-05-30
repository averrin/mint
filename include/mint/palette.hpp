#ifndef __PALETTE_H_
#define __PALETTE_H_
#include <string>
#include "cinder/gl/gl.h"

struct Palette {
    std::string name;
    ci::Color fgColor;
    ci::Color bgColor;
};

/*
 // Dark
    @black:           #1d1f21; // 00
    @very-dark-gray:  #282a2e; // 01
    @dark-gray:       #373b41; // 02
    @gray:            #969896; // 03
    @light-gray:      #b4b7b4; // 04
    @very-light-gray: #c5c8c6; // 05
    @almost-white:    #e0e0e0; // 06
    @white:           #ffffff; // 07

    // Colors
    @red:             #cc6666; // 08
    @orange:          #de935f; // 09
    @yellow:          #f0c674; // 0A
    @green:           #b5bd68; // 0B
    @cyan:            #8abeb7; // 0C
    @blue:            #81a2be; // 0D
    @purple:          #b294bb; // 0E
    @brown:           #a3685a; // 0F
 */

/*
 // Light
    @black:           #1d1f21; // 00
    @very-dark-gray:  #282a2e; // 01
    @dark-gray:       #373b41; // 02
    @gray:            #969896; // 03
    @light-gray:      #b4b7b4; // 04
    @very-light-gray: #c5c8c6; // 05
    @almost-white:    #e0e0e0; // 06
    @white:           #ffffff; // 07

    // Colors
    @red:             #cc6666; // 08
    @orange:          #de935f; // 09
    @yellow:          #f0c674; // 0A
    @green:           #b5bd68; // 0B
    @cyan:            #8abeb7; // 0C
    @blue:            #81a2be; // 0D
    @purple:          #b294bb; // 0E
    @brown:           #a3685a; // 0F
 */

#endif // __PALETTE_H_
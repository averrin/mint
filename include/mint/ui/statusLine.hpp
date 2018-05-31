#ifndef __STATUSLINE_H_
#define __STATUSLINE_H_

#include <string>

#include "mint/state.hpp"


class StatusLine {
public:
    StatusLine(std::shared_ptr<State> state);
    void setText(std::string msg);
    void clear();

private:
    std::shared_ptr<State> state;
};


#endif // __STATUSLINE_H_

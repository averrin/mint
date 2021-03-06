#ifndef __STATUSLINE_H_
#define __STATUSLINE_H_

#include <string>

#include "mint/state.hpp"
#include "mint/fragment.hpp"


class StatusLine {
public:
    StatusLine(std::shared_ptr<State> state);
    void setContent(Fragments content);
    void clear();

    static const int HEIGHT = 30;

private:
    std::shared_ptr<State> state;
};


#endif // __STATUSLINE_H_

#ifndef __FRAGMENT_H_
#define __FRAGMENT_H_

#include <string>
#include <map>
#include <variant>
#include <functional>
#include <memory>

#include "CinderPango.h"

typedef std::variant<int, float, bool, std::string> tpl_arg;

class State;
struct MintEvent {
    virtual ~MintEvent() {};
};
class Fragment {
public:
        Fragment(std::string t, std::map<std::string, tpl_arg> args);
        Fragment(std::string t);
        std::string render(State s);

        int index;
        int length;
        PangoRectangle rect;

        virtual ~Fragment();

protected:
        std::string template_str;
        std::map<std::string, tpl_arg> args;
};

class Link : public Fragment {
public:
        Link(std::string title, std::shared_ptr<MintEvent> cb);
        std::shared_ptr<MintEvent> callback;
        ~Link();
};

class Loader : public Fragment {
public:
        Loader(std::string);
        int counter = 0;

        std::string charSet = "⠁⠉⠙⠹⢹⣹⣽⣿⣷⣧⣇⡇⠇⠃";
        std::string charSetAlt = "⠁⠈⠐⠠⢀⡀⠄⠂";

        void tick();
        void done(std::string);
};

typedef std::vector<std::shared_ptr<Fragment>> Fragments;

#endif // __FRAGMENT_H_

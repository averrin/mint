#ifndef __FRAGMENT_H_
#define __FRAGMENT_H_

#include <string>
#include <map>
#include <variant>
#include <functional>

typedef std::variant<int, float, bool, std::string> tpl_arg;

class State;
class Fragment {
public:
        Fragment(std::string t, std::map<std::string, tpl_arg> args);
        Fragment(std::string t);
        std::string render(State s);
private:
        std::string template_str;
        std::map<std::string, tpl_arg> args;
};

typedef std::function<void()> linkCallback;
class Link : public Fragment {
public:
        Link(std::string title, linkCallback cb);
        linkCallback callback;
};

#endif // __FRAGMENT_H_

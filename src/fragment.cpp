#include <variant>

#include "mint/fragment.hpp"
#include "mint/actions.hpp"
#include "mint/state.hpp"
#include "Jinja2CppLight.h"

using namespace Jinja2CppLight;
using namespace std::string_literals;

Fragment::Fragment(std::string t, std::map<std::string, tpl_arg> a): template_str(t), args(a) {}; 
Fragment::Fragment(std::string t): template_str(t) {}; 

Fragment::~Fragment(){};
Link::~Link(){};

std::string Fragment::render(State state) {
    Template tpl( template_str );

    tpl.setValue( "green", state.currentPalette.green);
    tpl.setValue( "red", state.currentPalette.red);
    tpl.setValue( "blue", state.currentPalette.blue);

    for (auto [key, value] : args) {
        std::visit([&](auto const & val) { tpl.setValue(key, val); }, value);
    }

    return tpl.render();
}

Link::Link(std::string title, std::shared_ptr<MintEvent> cb) :
    Fragment(State::LINK, {{"title", title}}),
    callback(cb)
{};

Loader::Loader(std::string title) : Fragment(State::LOADER, {{"title", title}, {"char", "⠁"s}}) {};
void Loader::tick() {
    counter++;
    if (counter >= charSet.size()) counter = 0;
    args["char"] = charSet[counter];
};

void Loader::done(std::string title) {
    template_str = title;
};

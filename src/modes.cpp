#include <memory>

#include "mint/modes.hpp"

ModeManager::ModeManager() {};

void ModeManager::processKey(KeyEvent event) {
    state_machine.process_event(KeyPressedEvent(event));
}

void ModeManager::processEvent(std::shared_ptr<MintEvent> event) {
    state_machine.process_event(*event);
}

void ModeManager::toNormal() {
   // processEvent(std::make_shared<ModeExitedEvent>());
    state_machine.process_event(ModeExitedEvent{});
}

void HintsMode::processEvent(std::shared_ptr<MintEvent> event) {
    auto e = std::dynamic_pointer_cast<ChangePaletteEvent>(event);
    if (e) {
        steps->state->currentPalette = e->palette;
    }
}

Mode::Mode(std::shared_ptr<Steps> s): steps(s) {};

bool HintsMode::processKey(KeyEvent event) {
    auto k = links_cache.find(std::string{event.getChar()});
    if (k != links_cache.end()) {
        processEvent((*k).second->callback);
        activated = false;
        return true;
    }
    return false;
}

std::map<std::string, std::shared_ptr<Link>> HintsMode::getLinks() {
    std::map<std::string, std::shared_ptr<Link>> links;
    std::vector<std::string> sh = {"f", "j", "d", "k", "s", "l"};
    auto n = 0;

    for (auto f : steps->state->fragments) {
        auto link = std::dynamic_pointer_cast<Link>(f);
        if (!link) continue;
        links.insert({sh[n], link});
        n++;
    }
    links_cache = links;
    return links;
};

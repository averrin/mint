#include "mint/modes.hpp"

ModeManager::ModeManager() {};

void ModeManager::processKey(KeyEvent event) {
    state_machine.process_event(KeyPressedEvent(event));
}

Mode::Mode(std::shared_ptr<Steps> s): steps(s) {};

void HintsMode::processKey(KeyEvent event) {
}

void LeaderMode::processKey(KeyEvent event) {
}

void NormalMode::processKey(KeyEvent event) {
}

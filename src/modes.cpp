#include "mint/modes.hpp"

ModeManager::ModeManager() {};

void ModeManager::processKey(KeyEvent event) {
    state_machine.process_event(KeyPressedEvent(event));
}



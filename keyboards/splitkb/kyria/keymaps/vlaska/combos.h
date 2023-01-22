#pragma once
#include QMK_KEYBOARD_H

enum combo_events {
    CAPS_WORD_COMBO,
    BACKSPACE_COMBO,
    COMBO_LENGTH
};

extern uint16_t COMBO_LEN;

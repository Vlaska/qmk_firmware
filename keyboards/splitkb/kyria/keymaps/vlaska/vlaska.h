#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
#include "tapdances.h"
#endif

enum keyboard_layers {
    _BASE = 0,
    _NUM,
    _NUMPAD,
    _NAV,
    _FUNC,
    _GAME,
};

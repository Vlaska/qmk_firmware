#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

#ifdef TAP_DANCE_ENABLE
#    include "tapdances.h"
#endif

#ifdef LEADER_ENABLE
#    include "leader.h"
#endif

#ifdef COMBO_ENABLE
#    include "combos.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    define COLON TD_COLON
#    define QUOTE TD_QUOTE
#else
#    define COLON KC_SCLN
#    define QUOTE KC_QUOTE
#endif

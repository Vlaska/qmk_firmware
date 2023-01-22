#include "combos.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM spc_sftent_combo[] = {KC_SPACE, KC_SFTENT, COMBO_END};
const uint16_t PROGMEM lalt_altgr_combo[] = {KC_LCTL, KC_RALT, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [CAPS_WORD_COMBO] = COMBO(spc_sftent_combo, QK_CAPS_WORD_TOGGLE),
    [BACKSPACE_COMBO] = COMBO(lalt_altgr_combo, KC_BACKSPACE),
};

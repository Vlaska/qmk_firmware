#include "tapdances.h"

void generic_swapable_tap_dance_finished(qk_tap_dance_state_t *state, void *user_data, uint16_t swapped_key, uint16_t unswapped_key, bool swap) {
    if (state->count == 1 && swap) {
        register_code16(swapped_key);
    } else {
        register_code16(unswapped_key);
    }
}

void generic_swapable_tap_dance_reset(qk_tap_dance_state_t *state, void *user_data, uint16_t swapped_key, uint16_t unswapped_key, bool swap) {
    if (state->count == 1 && swap) {
        unregister_code16(swapped_key);
    } else {
        unregister_code16(unswapped_key);
    }
}

bool SWAP_COLN_SEMICOLN = true;
bool SWAP_QUOTES = false;

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    generic_swapable_tap_dance_finished(state, user_data, KC_COLON, KC_SEMICOLON, SWAP_COLN_SEMICOLN);
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    generic_swapable_tap_dance_reset(state, user_data, KC_COLON, KC_SEMICOLON, SWAP_COLN_SEMICOLN);
}

void dance_quote_finished(qk_tap_dance_state_t *state, void *user_data) {
    generic_swapable_tap_dance_finished(state, user_data, KC_DOUBLE_QUOTE, KC_QUOTE, SWAP_QUOTES);
}

void dance_quote_reset(qk_tap_dance_state_t *state, void *user_data) {
    generic_swapable_tap_dance_reset(state, user_data, KC_DOUBLE_QUOTE, KC_QUOTE, SWAP_QUOTES);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [CT_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quote_finished, dance_cln_reset),
};

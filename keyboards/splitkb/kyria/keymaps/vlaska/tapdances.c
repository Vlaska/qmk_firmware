#include "tapdances.h"

tap_dance_tap_hold_t colon_tap_dance = {KC_COLN, KC_SCLN, KC_NO};
tap_dance_tap_hold_t quote_tap_dance = {KC_QUOTE, KC_DOUBLE_QUOTE, KC_NO};

tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN]   = ACTION_TAP_DANCE_TAP_HOLD(colon_tap_dance),
    [CT_QUOTE] = ACTION_TAP_DANCE_TAP_HOLD(quote_tap_dance),
};

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
    uint16_t              key;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            key = tap_hold->hold;
        } else {
            key = tap_hold->tap;
        }

        register_code16(key);
        tap_hold->held = key;
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

void swap_tap_dance_tap_hold(void *dance_) {
    tap_dance_tap_hold_t *dance = (tap_dance_tap_hold_t *)dance_;
    uint16_t              tmp   = dance->tap;
    dance->tap                  = dance->hold;
    dance->hold                 = tmp;
}

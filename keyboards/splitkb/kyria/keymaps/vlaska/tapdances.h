#pragma once
#include QMK_KEYBOARD_H

#ifdef LEADER_ENABLE
#    include "leader.h"
#endif

// Tap dance indexes
enum {
    CT_CLN,
    CT_QUOTE,
};

#define TD_COLON TD(CT_CLN)
#define TD_QUOTE TD(CT_QUOTE)

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

tap_dance_tap_hold_t colon_tap_dance;
tap_dance_tap_hold_t quote_tap_dance;
tap_dance_action_t tap_dance_actions[2];

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_TAP_HOLD(tap_hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)(&tap_hold), }

void swap_tap_dance_tap_hold(void *dance_);

#pragma once
#include QMK_KEYBOARD_H

// Tap dance indexes
enum {
    CT_CLN,
    CT_QUOTE,
};

#define TD_COLON TD(CT_CLN)
#define TD_QUOTE TD(CT_QUOTE)

bool SWAP_COLN_SEMICOLN;
bool SWAP_QUOTES;

    void
    generic_swapable_tap_dance_finished(qk_tap_dance_state_t *action, void *user_data, uint16_t swapped_key, uint16_t unswapped_key, bool swap);

// Tap dance for : and ;
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap dance for ' and "
void dance_quote_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_quote_reset(qk_tap_dance_state_t *state, void *user_data);

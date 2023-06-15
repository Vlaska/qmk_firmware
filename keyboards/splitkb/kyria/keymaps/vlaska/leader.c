#include "leader.h"

bool leader_in_progress = false;

void leader_start_user(void) {
    leader_in_progress = true;
    layer_clear();
    layer_on(_BASE);
}

void leader_end_user(void) {
    leader_in_progress = false;
#ifdef TAP_DANCE_ENABLE
    if (leader_sequence_two_keys(KC_D, KC_S)) {
        swap_tap_dance_tap_hold(tap_dance_actions[CT_CLN].user_data);
    } else if (leader_sequence_two_keys(KC_D, KC_Q)) {
        swap_tap_dance_tap_hold(tap_dance_actions[CT_QUOTE].user_data);
    } else
#endif
        if (leader_sequence_one_key(KC_A)) {
        SEND_STRING("->");
    } else if (leader_sequence_one_key(KC_R)) {
        register_code(KC_LGUI);
        register_code(KC_LEFT_CTRL);
        register_code(KC_T);

        unregister_code(KC_T);
        unregister_code(KC_LEFT_CTRL);
        unregister_code(KC_LGUI);
    }
}

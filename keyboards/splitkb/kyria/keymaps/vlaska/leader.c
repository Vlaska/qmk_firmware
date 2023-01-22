#include "leader.h"

bool leader_in_progress = false;

void leader_start(void) {
    leader_in_progress = true;
    layer_clear();
    layer_on(_BASE);
}

void leader_end(void) {
    leader_in_progress = false;
}

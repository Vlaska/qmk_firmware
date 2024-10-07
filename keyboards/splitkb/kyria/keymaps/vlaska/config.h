/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#if defined(KEYBOARD_splitkb_kyria_rev2)
#    ifdef RGBLIGHT_ENABLE
// #    define RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_HUE_STEP 8
#        define RGBLIGHT_SAT_STEP 8
#        define RGBLIGHT_VAL_STEP 8
#        define RGBLIGHT_LIMIT_VAL 255
#    endif

// Turn off rgb lights when host went to sleep/is turned off
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_DEFAULT_HUE 127

// Space optimizations
#    define LAYER_STATE_8BIT

// Disable RGB light animations
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLIGHT_EFFECT_BREATHING
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_SNAKE
#    undef RGBLIGHT_EFFECT_KNIGHT
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#    undef RGBLIGHT_EFFECT_RGB_TEST
#    undef RGBLIGHT_EFFECT_ALTERNATING
#    undef RGBLIGHT_EFFECT_TWINKLE

#elif defined(KEYBOARD_splitkb_kyria_rev3)
#    ifdef RGBLIGHT_ENABLE
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_EFFECT_RAINBOW_MOOD
#        define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#        define RGBLIGHT_EFFECT_SNAKE
#        define RGBLIGHT_EFFECT_KNIGHT
#        define RGBLIGHT_EFFECT_CHRISTMAS
#        define RGBLIGHT_EFFECT_STATIC_GRADIENT
#        define RGBLIGHT_EFFECT_RGB_TEST
#        define RGBLIGHT_EFFECT_ALTERNATING
#        define RGBLIGHT_EFFECT_TWINKLE
#        define RGBLIGHT_HUE_STEP 8
#        define RGBLIGHT_SAT_STEP 8
#        define RGBLIGHT_VAL_STEP 8
#        ifndef RGBLIGHT_LIMIT_VAL
#            define RGBLIGHT_LIMIT_VAL 150
#        endif
#        define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#        define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#    endif
#endif

// Tap once for keys requiring multiple taps to do smth
#define TAPPING_TOGGLE 1

// Space optimizations
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

// Leader key and tapping
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define TAPPING_TERM 200
#define LEADER_KEY_STRICT_KEY_PROCESSING

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

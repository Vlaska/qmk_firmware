/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "vlaska.h"

// Aliases for readability
#define NUM TT(_NUM)
#define NAV TT(_NAV)
#define FKEYS OSL(_FUNC)
#define GAME TG(_GAME)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// Key combos
// Windows Task Manager
#define MANAGER RCS(KC_ESC)
// Print Screen section of screen (ShareX)
#define PRN_SCR LCTL(KC_PRINT_SCREEN)
// VS Code comment (CTRL + /)
#define VS_COMM LCTL(KC_SLASH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Left  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | '    " |
 * |  Shift |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Grave |   Z  |   X  |   C  |   V  |   B  |   [  |Print |  |F-keys|   ]  |   N  |   M  | ,  < | . >  | /  ? | \    | |
 * |  ESC   |      |      |      |      |      |      |Screen|  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Left | Left | Ctrl | Space| Nav  |  |  Num | Shift| AltGr| Left | Lead |
 *                        | Alt  | GUI  |      |      |      |  |      | Enter|      | Shift|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,    KC_U ,  KC_I ,   KC_O ,  KC_P ,   KC_BSPC,
     KC_LSFT , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,    KC_J ,  KC_K ,   KC_L ,  COLON,   QUOTE,
     QK_GESC , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC, PRN_SCR,     FKEYS ,KC_RBRC,  KC_N,    KC_M ,  KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                                KC_LALT, KC_LGUI, KC_LCTL, KC_SPC , NAV    ,     NUM   ,SC_SENT,  KC_RALT, KC_LSFT,QK_LEAD
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp|        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI | Ctrl | Shift|  Alt |      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | Caps |  | Manag|      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * |        |      |      |      |      |      |      | Lock |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | Lead |  |  Tab | Bksp |Delete|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, DM_REC1,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______,
      _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, DM_PLY1,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, KC_CAPS, _______, _______, MANAGER, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, QK_LEAD, _______, _______, KC_TAB , KC_BSPC,  KC_DEL, _______, _______
    ),

/*
 * Num Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   `    |   {  |   }  |   &  |   |  |   #  |                              |   (  | 7  & | 8  * | 9  ( |   =  |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   <  |   >  |   =  |   ~  |   -  |                              |   )  | 4  $ | 5  % | 6  ^ |   +  |    -   |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   [  |   ]  |   _  |   !  |   ?  |      |      |  |      |      |   :  | 1  ! | 2  @ | 3  # |   *  |    /   |
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Left |      |      |  |      |      | 0  ) |   .  |   ,  |
 *                        |      |      | Shift|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      KC_GRV,  KC_LCBR, KC_RCBR, KC_AMPR, KC_PIPE, KC_HASH,                                     KC_LPRN, KC_7, KC_8, KC_9, KC_EQL,  _______,
      _______, KC_LT,   KC_GT,   KC_EQL,  KC_TILD, KC_PMNS,                                     KC_RPRN, KC_4, KC_5, KC_6, KC_PPLS, KC_PMNS,
      _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_EXLM, KC_QUES, _______, _______, _______, _______, KC_COLN, KC_1, KC_2, KC_3, KC_PAST, KC_PSLS,
                                 _______, _______, KC_LSFT, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_COMM
    ),
/*
 * Func layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  | CTRL |                              |      |  F13 |  F14 |  F15 |  F16 |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  | SHIFT|                              |      |  F17 |  F18 |  F19 |  F20 |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |  ALT |      |      |  |      |      |      |  F21 |  F22 |  F23 |  F24 |        |
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_LCTL,                                     _______, KC_F13,  KC_F14, KC_F15, KC_F16, _______,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LSFT,                                     _______, KC_F17,  KC_F18, KC_F19, KC_F20, _______,
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LALT, _______, _______, _______, _______, _______, KC_F21,  KC_F22, KC_F23, KC_F24, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

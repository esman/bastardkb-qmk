/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "keycodes.h"
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_UPPER,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_WIN,
    // LAYER_MOUSE
};

#define UPPER MO(LAYER_UPPER)
#define NAV MO(LAYER_NAV)
#define NUM MO(LAYER_NUM)
#define WIN MO(LAYER_WIN)
// #define MOUSE MO(LAYER_MOUSE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_EXLM, KC_LPRN, KC_RPRN,  KC_EQL, KC_MINS,    KC_UNDS, KC_ASTR, KC_RCBR, KC_LCBR, KC_PLUS,  KC_GRV,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           NAV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           NUM,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LCTL,   UPPER,     WIN,    KC_BSPC,  KC_SPC,
                                           KC_LCTL, KC_LSFT,     KC_INS
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

#define SHENT  S(KC_ENT)
#define SHINS  S(KC_INS)
#define SHTAB  S(KC_TAB)
#define SHSPC  S(KC_SPC)
#define SHBSPC S(KC_BSPC)

  [LAYER_UPPER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_QUES,   KC_AT, KC_HASH, KC_DLR, KC_MINS,    KC_UNDS, KC_AMPR, KC_RBRC, KC_LBRC, KC_CIRC, KC_TILD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         SHTAB, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),    S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_PIPE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           NAV, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),    S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN, KC_DQUO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           NUM, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),    S(KC_N), S(KC_M),   KC_LT,   KC_GT, KC_PERC,   SHENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LCTL, _______, XXXXXXX,     SHBSPC,   SHSPC,
                                           KC_LCTL, KC_LSFT,      SHINS
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

#define C_HOME C(KC_HOME)
#define C_END  C(KC_END)
#define C_PGUP C(KC_PGUP)
#define C_PGDN C(KC_PGDN)
#define C_LEFT C(KC_LEFT)
#define C_RGHT C(KC_RGHT)
#define C_UP C(KC_UP)
#define C_DOWN C(KC_DOWN)

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     C_HOME,  C_PGUP,  C_PGDN,   C_END, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     C_LEFT,  C_DOWN,    C_UP,  C_RGHT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_7, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_X,    KC_0,    KC_1,    KC_2,    KC_3, KC_PLUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_9,    KC_8,  KC_DOT, XXXXXXX,  KC_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

#define TOW_L G(KC_LEFT)   // Move TO window left
#define TOW_R G(KC_RGHT)   // Move TO window right
#define TOW_U G(KC_UP)     // Move TO window up
#define TOW_D G(KC_DOWN)   // Move TO window down
#define MOW_L LSG(KC_LEFT) // Move window left
#define MOW_R LSG(KC_RGHT) // Move window right
#define MOW_U LSG(KC_UP)   // Move window up
#define MOW_D LSG(KC_DOWN) // Move window down
#define TOW_1 G(KC_1)      // Move TO workspace 1
#define TOW_2 G(KC_2)      // Move TO workspace 2
#define TOW_3 G(KC_3)      // Move TO workspace 3
#define TOW_4 G(KC_4)      // Move TO workspace 4
#define TOW_9 G(KC_9)      // Move TO workspace 9
#define MOW_1 LSG(KC_1)    // Move window to workspace 1
#define MOW_2 LSG(KC_2)    // Move window to workspace 2
#define MOW_3 LSG(KC_3)    // Move window to workspace 3
#define MOW_4 LSG(KC_4)    // Move window to workspace 4
#define MOW_9 LSG(KC_9)    // Move window to workspace 9

#define WINDRCT G(KC_BSPC)
#define WINOPEN G(KC_SPC)
#define WINCLOS LSG(KC_Q)
#define WINFSCR G(KC_F)
#define WINFLOT LSG(KC_F)
#define WINTERM G(KC_ENT)
#define WINWEB  LSG(KC_ENT)
#define WINSTGS G(KC_C)
#define WINLOUT G(KC_T)

  [LAYER_WIN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MOW_9,   MOW_1,   MOW_2,   MOW_3,   MOW_4, WINLOUT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      TOW_9,   TOW_1,   TOW_2,   TOW_3,   TOW_4, WINSTGS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      TOW_L,   TOW_D,   TOW_U,   TOW_R, WINFSCR,  WINWEB,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MOW_L,   MOW_D,   MOW_U,   MOW_R, WINFLOT, WINTERM,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    WINDRCT, WINOPEN,
                                           XXXXXXX, XXXXXXX,    WINCLOS
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

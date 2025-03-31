// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
//          0           1           2           3       4       5       6       7       8       9           10      11              12                  13                  14              15
/* 0 */     KC_ESC,     KC_F1,      KC_F2,      KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,      KC_F10, KC_F11,         KC_F12,             KC_F13,             KC_HOME,

/* 1 */     KC_GRAVE,   KC_1,       KC_2,       KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0,   KC_MINUS,       KC_EQL,             KC_BACKSPACE,                       KC_END,
/* 2 */     KC_TAB,     KC_Q,       KC_W,       KC_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,           KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,   KC_BACKSLASH,   KC_PGUP,
/* 3 */     KC_LCTL,    KC_A,       KC_S,       KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,       KC_L,   KC_SEMICOLON,   KC_QUOTE,                               KC_ENTER,       KC_PGDN,
/* 4 */     KC_LSFT,    KC_Z,       KC_X,       KC_C,   KC_V,   KC_B,           KC_N,   KC_M,   KC_COMMA,   KC_DOT, KC_SLASH,       KC_RIGHT_SHIFT,                         KC_UP,
/* 5 */     KC_LCTL,    KC_LGUI,    KC_LALT,            KC_SPC, KC_NO,          KC_SPC,         KC_RALT,                                                KC_LEFT,            KC_DOWN,        KC_RGHT
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// If console is enabled, it will print the matrix position and status of each
// key pressed
#ifdef CONSOLE_ENABLE

    const char *key_name = get_keycode_string(keycode);
    uprintf("kc: 0x%04X (%-7s), row: %2u, col: %2u, pressed: %u, "
            "time: %5u, int: %u, count: %u\n",
            keycode, key_name,
            record->event.key.row, record->event.key.col,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count);
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      /*              0         1        2        3        4        5            6        7        8         9        10        11        12        13        14        15 */
      /* 0, pcb 5 */  KC_ESC,   KC_F1,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,   KC_F12,   KC_F13,   KC_F14,             KC_MUTE,
      /* 1, pcb 4 */  KC_GRAVE, KC_1,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,     KC_0,    KC_MINUS, KC_EQL,   KC_BSPC,            KC_HOME,  KC_END,
      /* 2, pcb 3 */  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_INS,   KC_PGUP,
      /* 3, pcb 2 */  MO(1),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,           KC_ENTER, KC_DEL,   KC_PGDN,
      /* 4, pcb 1 */  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,           KC_RSFT,            KC_UP,
      /* 5, pcb 0 */  KC_LCTL,  KC_LGUI, KC_2,    KC_LALT, KC_SPC,  KC_LGUI,     KC_SPC,  KC_F2,   KC_RALT,           KC_RCTL,            KC_LEFT,            KC_DOWN,  KC_RGHT,
      /* 5-way    */  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [1] = LAYOUT(
                      QK_BOOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MPLY,
                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,   KC_TRNS,
                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MPLY, KC_MPRV,  KC_MNXT, KC_TRNS,  KC_TRNS,            KC_TRNS, KC_TRNS,   KC_TRNS,
                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MUTE, KC_VOLD,  KC_VOLU, KC_TRNS,            KC_TRNS,           KC_TRNS,
                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,
      /* 5-way    */  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_MAP_ENABLE)

#define NUM_DIRECTIONS 2

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
};

#endif

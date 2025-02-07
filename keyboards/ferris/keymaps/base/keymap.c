#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LSFT_T(KC_A), LCTL_T(KC_S), LGUI_T(KC_D), LALT_T(KC_F), KC_G, KC_H, RALT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(2,KC_BSPC), LT(3,KC_SPC), LT(4,KC_TAB), LT(5,KC_ENT)),
        [1] = LAYOUT_split_3x5_2(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, LSFT_T(KC_A), LCTL_T(KC_O), LGUI_T(KC_E), LALT_T(KC_U), KC_I, KC_D, RALT_T(KC_H), RGUI_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, LT(2,KC_BSPC), LT(3,KC_SPC), LT(4,KC_TAB), LT(5,KC_ENT)),
        [2] = LAYOUT_split_3x5_2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PPLS, KC_7, KC_8, KC_9, KC_PMNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_PAST, KC_4, KC_5, KC_6, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQL, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_PDOT, KC_0),
        [3] = LAYOUT_split_3x5_2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO),
        [4] = LAYOUT_split_3x5_2(KC_NO, KC_PIPE, KC_LCBR, KC_RCBR, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_LPRN, KC_RPRN, KC_QUOT, KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO, KC_TILD, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
        [5] = LAYOUT_split_3x5_2(DF(1), KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, DF(0), KC_BSPC, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
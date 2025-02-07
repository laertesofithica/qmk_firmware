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
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMBER = 1,
    LAYER_FUNCTION = 2,
    LAYER_SYMBOLS = 3,
	LAYER_NAVIGATION = 4,
	LAYER_POINTER = 5,
	LAYER_MEDIA = 6
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 2000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 2
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_NUMBER)
#define RAISE MO(LAYER_FUNCTION)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off LAYOUT_charybdis_4x6
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, LSFT_T(KC_A), LCTL_T(KC_S), LGUI_T(KC_D), LALT_T(KC_F), KC_G, KC_H, RALT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_NO, KC_NO, LT(5,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, LT(6,KC_BSPC), LT(1,KC_SPC), LT(2,KC_DEL), LT(3,KC_TAB), LT(4,KC_ENT), KC_BTN1, KC_BTN2, LT(5,KC_ESC)),
        [1] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_TOG, RGB_RMOD, KC_NO, KC_NO, KC_PPLS, KC_7, KC_8, KC_9, KC_PMNS, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_PAST, KC_4, KC_5, KC_6, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT, KC_NO, KC_NO, KC_EQL),
        [2] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_TOG, RGB_RMOD, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS),
        [3] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_QUOT, KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS),
        [4] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS),
        [5] = LAYOUT_charybdis_4x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_W, DPI_MOD, S_D_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO, KC_NO, KC_NO, DRGSCRL, KC_C, KC_V, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN3, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_NO)
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE

	// =======================================================================
	#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
	report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
		if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
			if (auto_pointer_layer_timer == 0) {
				layer_on(LAYER_POINTER);
	#        ifdef RGB_MATRIX_ENABLE
				rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
				rgb_matrix_sethsv_noeeprom(HSV_GREEN);
	#        endif // RGB_MATRIX_ENABLE
			}
			auto_pointer_layer_timer = timer_read();
		}
		return mouse_report;
	}
	
	void matrix_scan_user(void) {
		if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
			auto_pointer_layer_timer = 0;
			layer_off(LAYER_POINTER);
	#        ifdef RGB_MATRIX_ENABLE
			rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
	#        endif // RGB_MATRIX_ENABLE
		}
	}
	#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
	// =======================================================================

	// =======================================================================
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
	charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    switch (get_highest_layer(state)) {
        case LAYER_BASE:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
            break;
        case LAYER_NUMBER:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
		case LAYER_FUNCTION:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            break;
		case LAYER_SYMBOLS:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
		case LAYER_NAVIGATION:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
		case LAYER_POINTER:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;
		case LAYER_MEDIA:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
			rgb_matrix_sethsv_noeeprom(HSV_TURQUOISE);
            break;
        default: // for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
            break;
    }
  return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
	// =======================================================================

	// =======================================================================
#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(RGB_RED);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
	// =======================================================================


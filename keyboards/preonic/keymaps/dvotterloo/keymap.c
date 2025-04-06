/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum layers {
  _COLEMAK,
  _QWERTY,
  _ONE_HANDED_DVORAK_RIGHT,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  COLEMAK = QK_USER,
  QWERTY,
  ONE_HANDED_DVORAK_RIGHT,
	LOWER,
 	RAISE
};


// todo
//  - [ ] numlock beep
//  - [ ] shift backspace = delete
//  - [ ] enable midi keyboard
//  - [ ] disable leds

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* Colemak Mod-DH (ANSI)
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Bksp |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   X  |   C  |   D  |   V  |   Z  |   K  |   H  |   ,  |   .  |   /  |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | Alt  | GUI  | Ctrl |Space |Lower |Raise |Enter | Alt  | GUI  |  APP | Ctrl |
  * `-----------------------------------------------------------------------------------'
  */
  [_COLEMAK] = LAYOUT_preonic_grid(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
    KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_EQL,
    KC_BSPC,    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
    KC_LSFT,    KC_X,       KC_C,       KC_D,       KC_V,       KC_Z,       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFT_T(KC_BSLS),
    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LCTL,    KC_SPC,     LOWER,      RAISE,      KC_ENT,     KC_RALT,    KC_RGUI,    KC_APP,     KC_RCTL
  ),


  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | Alt  | GUI  | Ctrl |Space |Lower |Raise |Enter | Alt  | GUI  |  APP | Ctrl |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_preonic_grid(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
    KC_BSPC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFT_T(KC_BSLS),
    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LCTL,    KC_SPC,     LOWER,      RAISE,      KC_ENT,     KC_RALT,    KC_RGUI,    KC_APP,     KC_RCTL
  ),


  /* One-Handed Dvorak (Right Hand)
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   J  |   L  |   M  |   F  |   P  |   /  |   \  |
  * |----- +------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   5  |   6  |   Q  |   .  |   O  |   R  |   S  |   U  |   Y  |   B  |   ;  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Bksp |   7  |   8  |   Z  |   A  |   E  |   H  |   T  |   D  |   C  |   K  |   -  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   9  |   0  |   X  |   ,  |   I  |   N  |   W  |   V  |   G  |   '  |   =  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | Alt  | GUI  | Ctrl |Space |Lower |Raise |Enter |Space | Bksp | Shift| Lower|
  * `-----------------------------------------------------------------------------------'
  *
  */
  [_ONE_HANDED_DVORAK_RIGHT] = LAYOUT_preonic_grid(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_J,       KC_L,       KC_M,       KC_F,      KC_P,        KC_SLSH,    KC_BSLS,
    KC_TAB,     KC_5,       KC_6,       KC_Q,       KC_DOT,     KC_O,       KC_R,       KC_S,       KC_U,      KC_Y,        KC_B,       KC_SCLN,
    KC_BSPC,    KC_7,       KC_8,       KC_Z,       KC_A,       KC_E,       KC_H,       KC_T,       KC_D,      KC_C,        KC_K,       KC_MINS,
    KC_LSFT,    KC_9,       KC_0,       KC_X,       KC_COMM,    KC_I,       KC_N,       KC_W,       KC_V,      KC_G,        KC_QUOT,    KC_EQL,
    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LCTL,    KC_SPC,     LOWER,      RAISE,      KC_ENT,     KC_SPC,    KC_BSPC,     KC_LSFT,    LOWER
  ),

  /*
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_preonic_grid(
    KC_TILD,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P7,      KC_P8,      KC_P9,     KC_PSLS,    KC_NUM,
    _______,    KC_MPRV,    KC_VOLU,    KC_VOLD,    KC_MNXT,    _______,    _______,    KC_P4,      KC_P5,      KC_P6,     KC_PAST,    KC_PEQL,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P1,      KC_P2,      KC_P3,     KC_PMNS,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P0,      KC_PCMM,    KC_PDOT,   KC_PPLS,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PENT,    _______,    _______,   _______,    _______
  ),


  /*
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |     |       |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_preonic_grid(
    _______,    KC_F1,    	KC_F2,    	KC_F3,   	  KC_F4,  	  KC_F5,  	  KC_F6,    	KC_F7,  	  KC_F8,    	KC_F9,    	KC_F10,     _______,
    _______,    KC_F11,    	KC_F12,    	KC_F13,   	KC_F14,  	  _______,    _______,    KC_LBRC,  	KC_RBRC,    KC_LCBR,    KC_RCBR,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,  	KC_UP,      KC_DOWN,    KC_RIGHT,   _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
  ),


  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |     |       |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_preonic_grid(
    QK_BOOT,    KC_F11,    	KC_F12,    	KC_F13,   	KC_F14,  	  KC_F15,  	  KC_F16,    	KC_F17,  	  KC_F18,    	KC_F19,    	KC_F20,     COLEMAK,
    _______,    KC_F21,    	KC_F22,    	KC_F23,   	KC_F24,     _______,    _______,    _______,    _______,   _______,     _______,    QWERTY,
    KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,    ONE_HANDED_DVORAK_RIGHT,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case ONE_HANDED_DVORAK_RIGHT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ONE_HANDED_DVORAK_RIGHT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	return keycode == RSFT_T(KC_BSLS);
}
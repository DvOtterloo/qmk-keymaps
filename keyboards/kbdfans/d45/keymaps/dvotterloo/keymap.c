/* Copyright 2022 dztech kbdfans
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

enum layers {
	_COLEMAK,
    _QWERTY,
	_LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    COLEMAK = QK_USER,
    QWERTY,
	LOWER,
 	RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
		KC_ESC, 	KC_TAB,    	KC_Q,     	KC_W,     	KC_F,  		KC_P,  		KC_B,  		KC_J,    	KC_L,  		KC_U,    	KC_Y,     	KC_SCLN,  		KC_LBRC,  		KC_RBRC, 		KC_MINS, 	KC_DEL,
		KC_F2,  	KC_BSPC,   	KC_A,     	KC_R,     	KC_S,  		KC_T,  		KC_G,  		KC_M,    	KC_N,  		KC_E,    	KC_I,     	KC_O,     		KC_QUOT,  		KC_EQL,  					KC_HOME,
		KC_F3,  	KC_LSFT,   	KC_X,     	KC_C,     	KC_D,  		KC_V,  		KC_Z,  		KC_K,    	KC_H,  		KC_COMM, 	KC_DOT,   	KC_SLSH,  		RSFT_T(KC_BSLS),KC_UP,   					KC_END,
		KC_LCTL,  	KC_LALT,   				LOWER,   	KC_SPC,		       		KC_ENT,		RAISE, 				    KC_RCTL,              	     			KC_LEFT,  		KC_DOWN, 		KC_RIGHT
	),

	[_QWERTY] = LAYOUT(
		_______, 	_______,   	KC_Q,     	KC_W,     	KC_E,  		KC_R,  		KC_T,  		KC_Y,    	KC_U,  		KC_I,    	KC_O,     	KC_P,	  		_______,  		_______, 		_______, 	_______,
		_______,  	_______,   	KC_A,     	KC_S,     	KC_D,  		KC_F,  		KC_G,  		KC_H,    	KC_J,  		KC_K,    	KC_L,     	KC_SCLN,     	_______,  		_______,  					_______,
		_______,  	_______,   	KC_Z,     	KC_X,     	KC_C,  		KC_V,  		KC_B,  		KC_N,    	KC_M,  		_______, 	_______,   	_______,  		_______,  		_______,   					_______,
		_______,  	_______,   				_______,  	_______,	       		_______,	_______, 				_______,              	     			_______,  		_______, 		_______
	),


	
	[_LOWER] = LAYOUT(
		KC_TILD, 	_______,	KC_EXLM, 	KC_AT,   	KC_HASH, 	KC_DLR,  KC_PERC, 		KC_CIRC, 	KC_AMPR,    KC_ASTR,    KC_LPRN, 	KC_RPRN, 		KC_LCBR,  		KC_RCBR, 		KC_UNDS,    _______,
		_______,  	_______,   	_______,    _______,    _______,   _______,  	_______,  	_______,    _______,  	_______,    _______,    _______,     	_______,  		KC_PLUS,  					_______,
		_______,  	_______,   	_______,    _______,    _______,  _______,  	_______,  	_______,    _______,  	_______, 	_______,   	_______,  		_______,  		_______,   					_______,
		_______,  	_______,   				_______,  	_______,	       		_______,	_______, 				_______,              	     			_______,  		_______, 		_______
	),

	
	[_RAISE] = LAYOUT(
		_______, 	_______,    KC_1,    	KC_2,    	KC_3,    	KC_4,    	KC_5,    	KC_6,    	KC_7,    	KC_8,    	KC_9,    	KC_0,    		_______,	    _______,  		_______, 	_______,
		_______,  	_______,   	_______,    _______,    _______,   _______,  	_______,  	_______,    _______,  	_______,    _______,    _______,     	_______,  		_______,  					_______,
		_______,  	_______,   	_______,    _______,    _______,   _______,  	_______,  	_______,    _______,  	_______, 	_______,   	_______,  		_______,  		_______,   					_______,
		_______,  	_______,   				_______,  	_______,	       		_______,	_______, 				_______,              	     			_______,  		_______, 		_______
	),

	
	[_ADJUST] = LAYOUT(
		_______, 	_______,   	KC_F1,    	KC_F2,    	KC_F3,   	KC_F4,  	KC_F5,  	KC_F6,    	KC_F7,  	KC_F8,    	KC_F9,    	KC_F10,	    	_______,  		_______, 		_______, 	_______,
		_______,  	_______,   	KC_F11,    	KC_F12,    	KC_F13,   	KC_F14,  	KC_F15,  	KC_F16,    	KC_F17,  	KC_F18,    	KC_F19,    	KC_F20,     	_______,  		_______,  					_______,
		COLEMAK,  	_______,   	KC_F21,    	KC_F22,    	KC_F23,   	KC_F24,  	_______,  	_______,    _______,  	_______, 	_______,   	_______,  		_______,  		_______,   					_______,
		QWERTY,  	_______,   				_______,  	_______,	       		_______,	_______, 				_______,              	     			_______,  		_______, 		_______

	)
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	mod_state = get_mods();
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
		case KC_BSPC:
		{
			static bool delkey_registered;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					del_mods(MOD_MASK_SHIFT);
					register_code(KC_DEL);
					delkey_registered = true;
					set_mods(mod_state);
					return false;
				}
			} else {
				if (delkey_registered) {
					unregister_code(KC_DEL);
					delkey_registered = false;
					return false;
				}
			}
			return true;
		}
    }
    return true;
}

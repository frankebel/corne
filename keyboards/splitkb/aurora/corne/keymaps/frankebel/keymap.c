/* Copyright 2023 Frank Ebel <@frankebel>
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

enum layer_names {
    _COLEMAK,
    _NUMBER,
    _SYMBOL,
    _FUNCTION,
    _NAVIGATION,
    _MEDIA,
    _LAYER,
    _RALT,
    _ARROW,
};

// Layer keys
#define DF_COL DF(_COLEMAK)
#define DF_ARRO DF(_ARROW)
#define LT_FUN LT(_FUNCTION, KC_ESC)
#define LT_NUM LT(_NUMBER, KC_SPC)
#define LT_SYM LT(_SYMBOL, KC_TAB)
#define LT_LAY LT(_LAYER, KC_ENT)
#define LT_NAV LT(_NAVIGATION, KC_BSPC)
#define LT_MED LT(_MEDIA, KC_DEL)

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define HOME_V RALT_T(KC_V)

// Right-hand home row mods
#define HOME_N RGUI_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_O LALT_T(KC_O)
#define HOME_M RALT_T(KC_M)

// Helpful defines
#define KC_EURO RSFT_T(KC_5)
#define KC_MM LGUI(KC_SLSH) // mute microphone, set in compositor
int TAPPING_TERM_PINKY = 200;
int TAPPING_TERM_THUMB = 120;
int TAPPING_TERM_INDEX = 120;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
        _______, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_D,                             KC_H,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  _______,
        _______, KC_Z,    KC_X,    KC_C,    HOME_V,  KC_B,                             KC_K,    HOME_M,  KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            LT_FUN,  LT_NUM,  LT_SYM,         LT_LAY,  LT_NAV,  LT_MED
    ),

    [_NUMBER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, _______,                          KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
        _______, _______, _______, _______, _______, _______,                          KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
                                            _______, _______, _______,        KC_MINS, KC_0,    KC_DOT
    ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, _______,                          KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______,                          KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,
                                            _______, _______, _______,        KC_UNDS, KC_LPRN, KC_RPRN
    ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, _______,                          KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______,
        _______, _______, _______, _______, _______, _______,                          KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
        _______, _______, _______, KC_UP,   _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                          _______, KC_RGUI, KC_RSFT, KC_RCTL, KC_LALT, _______,
        _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,                           _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
        _______, _______, _______, KC_BRID, KC_BRIU, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                          _______, KC_RGUI, KC_RSFT, KC_RCTL, KC_LALT, _______,
        _______, _______, KC_MM,   _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_LAYER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, DF_ARRO, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DF_COL,  _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_RALT] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, _______, KC_Y,    _______, _______, _______,
        _______, KC_Q,    _______, HOME_S,  _______, _______,                          _______, _______, KC_EURO, _______, KC_P,    _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_ARROW] = LAYOUT_split_3x6_3(
        _______, _______, _______, KC_UP,   _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                          _______, _______, _______, _______, _______, _______,
        _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,                           _______, _______, _______, _______, _______, _______,
                                            _______, _______, DF_COL,         _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_V:
            if (!record->tap.count && record->event.pressed) {
                // Intercept hold function
                register_code(KC_RALT);
                layer_on(_RALT);
                return true;
            } else {
                unregister_code(KC_RALT);
                layer_off(_RALT);
            }
        case HOME_M:
            if (!record->tap.count && record->event.pressed) {
                // Intercept hold function
                register_code(KC_RALT);
                layer_on(_RALT);
                return true;
            } else {
                unregister_code(KC_RALT);
                layer_off(_RALT);
            }
    }
    return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Lower time for index finger.
        case HOME_S:
            return TAPPING_TERM_INDEX;
        case HOME_E:
            return TAPPING_TERM_INDEX;
        // Lower time for left Ctrl.
        case HOME_R:
            return TAPPING_TERM - 10;
        // Raise time for right ring finger.
        case HOME_I:
            return TAPPING_TERM + 10;
        // Lower time for thumbs.
        case LT_FUN:
            return TAPPING_TERM_THUMB;
        case LT_NUM:
            return TAPPING_TERM_THUMB;
        case LT_SYM:
            return TAPPING_TERM_THUMB;
        case LT_LAY:
            return TAPPING_TERM_THUMB;
        case LT_NAV:
            return TAPPING_TERM_THUMB;
        case LT_MED:
            return TAPPING_TERM_THUMB;
        // Raise time for pinkies.
        case HOME_A:
            return TAPPING_TERM_PINKY;
        case HOME_O:
            return TAPPING_TERM_PINKY;
        default:
            return TAPPING_TERM;
    }
}

/* Copyright 2021 Katrina (@PepperKats)
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
    BASE,
    TWO,
    L_RGB
};

enum custom_keys {
    RGB_M_RB = SAFE_RANGE, // RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    RGB_D_RAIN,  // RGB_MATRIX_DIGITAL_RAIN
    RGB_M_AM, // RGB_MATRIX_ALPHAS_MODS
    RGB_M_GUD, // RGB_MATRIX_GRADIENT_UP_DOWN
    RGB_M_GLR, // RGB_MATRIX_GRADIENT_LEFT_RIGHT
    RGB_M_BR, // RGB_MATRIX_BREATHING
    RGB_M_CA, // RGB_MATRIX_CYCLE_ALL
    RGB_M_MSP, // RGB_MATRIX_MULTISPLASH
    RGB_M_PFL, // RGB_MATRIX_PIXEL_FLOW
};

// Macros
#define MC_AMZN LSFT(LCTL(LGUI(KC_A)))
#define MC_MTG  LSFT(LCTL(LGUI(KC_M)))

// Linear Copy Combos (Copy Id, Copy Url, Copy Branch Name)
#define LCP_ID LGUI(KC_DOT)
#define LCP_URL LGUI(LSFT(KC_COMMA))
#define LCP_BR LGUI(LSFT(KC_DOT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ┌───┐   ┌───────┐┌───┬───┬───┐┌───┬───┬───┐
     * │ESC│   │KC_BSPC││F1 │F2 │F3 ││F4 │F5 │F6 │
     * └───┘   └───────┘└───┴───┴───┘└───┴───┴───┘
     * ┌───┬───┬───┬───┐┌───┬───┬───┐
     * │NUM│ / │ * │ - ││PAS│SCR│PSC│
     * ├───┼───┼───┼───┤├───┼───┼───┤┌───┐   ┌───┐
     * │ 7 │ 8 │ 9 │   ││INS│HOM│PGU││HOM│   │END│
     * ├───┼───┼───┤ + │├───┼───┼───┤├───┴───┴───┤
     * │ 4 │ 5 │ 6 │   ││END│DEL│PGD││           │
     * ├───┼───┼───┼───┤└───┼───┼───┘│           │
     * │ 1 │ 2 │ 3 │ E │    │UP │    │     B     │
     * ├───┴───┼───┤ N │┌───┼───┼───┐│           │
     * │   0   │DEL│ T ││LFT│DWN│RHT││           │
     * └───────┴───┴───┘└───┴───┴───┘└───────────┘
     */
    [BASE] = LAYOUT(
        MO(1),                TO(TWO),               RGB_RMOD,  RGB_TOG,  RGB_MOD,    KC_F1,    KC_F2,     QK_BOOT,
        KC_NUM,    KC_PSLS,   KC_PAST,   KC_PMNS,    KC_PAUS,   KC_SCRL,  KC_PSCR,
        KC_P7,     KC_P8,     KC_P9,     KC_PPLS,    KC_INS,    MC_MTG,   KC_PGUP,    KC_MPLY,             KC_END,
        KC_P4,     KC_P5,     KC_P6,                 LCP_ID,    LCP_URL,  LCP_BR,
        KC_P1,     KC_P2,     KC_P3,     KC_PENT,               KC_UP,                          KC_B,
        KC_P0,                KC_PDOT,               KC_LEFT,   KC_DOWN,  MC_AMZN
    ),
    [TWO] = LAYOUT(
        MO(2)  ,              TO(L_RGB),             BL_TOGG,   _______,  _______,    KC_A,     QK_RBT ,   _______,
        _______,   _______,   _______,   _______,    _______,   _______,  _______,
        _______,   _______,   _______,   _______,    _______,   _______,  _______,    _______,             _______,
        _______,   _______,   _______,               _______,   _______,  _______,
        _______,   _______,   _______,   _______,               _______,                        _______,
        _______,              _______,               _______,   _______,  _______
    ),
    [L_RGB] = LAYOUT(
        _______,              TO(BASE),              _______,   _______,  _______,    _______,   _______,   _______,
        _______,   _______,   _______,   _______,    _______,   _______,  _______,
        RGB_D_RAIN,RGB_M_PFL, _______,   _______,    _______,   _______,  _______,    RGB_TOG,              _______,
        RGB_M_MSP, RGB_M_GUD, RGB_M_GLR, _______,   _______,  _______,
        RGB_M_P,   RGB_M_B,   RGB_M_RB,  _______,               _______,                        _______,
        _______,              _______,               _______,   _______,  _______
    )
    // Transparent Layer:
    /* [_LAYER] = LAYOUT( */
    /*     _______,              _______,               _______,   _______,  _______,    _______,   _______,   _______, */
    /*     _______,   _______,   _______,   _______,    _______,   _______,  _______, */
    /*     _______,   _______,   _______,   _______,    _______,   _______,  _______,    _______,              _______, */
    /*     _______,   _______,   _______,               _______,   _______,  _______, */
    /*     _______,   _______,   _______,   _______,               _______,                        _______, */
    /*     _______,              _______,               _______,   _______,  _______ */
    /* ) */
};

// Encoder Order:
// 2: Right Small knob
// 1: Left Small knob
// 0: Big knob

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]  = {  ENCODER_CCW_CW(KC_F1  ,   KC_F2  ),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [TWO]   = {  ENCODER_CCW_CW(_______,   _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)},
    [L_RGB] = {  ENCODER_CCW_CW(RGB_SAD,   RGB_SAI),  ENCODER_CCW_CW(RGB_HUD, RGB_HUI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)}

    // Transparent Example
    // [_LAYER] = {  ENCODER_CCW_CW(_______,   _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)},
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_M_RB:
        rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
        break;
    case RGB_D_RAIN:
        rgb_matrix_mode(RGB_MATRIX_DIGITAL_RAIN);
        break;
    // Handling new RGB modes
    case RGB_M_AM:
        rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
        break;
    case RGB_M_GUD:
        rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
        break;
    case RGB_M_GLR:
        rgb_matrix_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
        break;
    case RGB_M_BR:
        rgb_matrix_mode(RGB_MATRIX_BREATHING);
        break;
    case RGB_M_CA:
        rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
        break;
    case RGB_M_MSP:
        rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
        break;
    case RGB_M_PFL:
        rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
        break;
  }
  return true;
}


/*NOTE FOR PERSON MODIFYING KEYMAP
The large knob press is mapped as KC_B, despite it not having one.
I'm not quite sure why, but the only reason it can't be clicked is because the potentiometer is different.
If you were to replace it with one that can be clicked, it would work. I shorted it and it does work.*/

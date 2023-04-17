// Copyright 2023 rti <mail@rtti.de>
// Copyright 2022 beekeeb
// Copyright 2019 Thomas Baart <thomas@splitkb.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _EXTRA,
  _ADDITIONAL
};


// Shortcuts to make keymap more readable
#define KC_A_SL LSFT_T(KC_A)
#define KC_EQSL LSFT_T(KC_EQL)
#define KC_S_AL LALT_T(KC_S)
#define KC_MIAL LALT_T(KC_MINS)
#define KC_D_GL LGUI_T(KC_D)
#define KC_BSGL LGUI_T(KC_BSLS)
#define KC_F_CL LCTL_T(KC_F)
#define KC_QUCL LCTL_T(KC_QUOT)


#define KC_SNSR RSFT_T(KC_SCLN)
#define KC_L_AL LALT_T(KC_L)
#define KC_RGAL LALT_T(KC_RGHT)
#define KC_K_GR RGUI_T(KC_K)
#define KC_UPGR RGUI_T(KC_UP)
#define KC_J_CR RCTL_T(KC_J)
#define KC_DOCR RCTL_T(KC_DOWN)

#define KC_SPLE LT(_EXTRA, KC_SPC)
#define KC_ENLE LT(_EXTRA, KC_ENT)

#define KC_TALA LT(_ADDITIONAL, KC_TAB)
#define KC_ESLA LT(_ADDITIONAL, KC_ESC)

/* // clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                    KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_A_SL,KC_S_AL,KC_D_GL,KC_F_CL,KC_G   ,                    KC_H   ,KC_J_CR,KC_K_GR,KC_L_AL,KC_SNSR,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                    KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,XXXXXXX,
  //└───────┴───────┴───────┴───────┼───────┼───────┼───────┐   ┌───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                                     KC_BSPC,KC_SPLE,KC_TALA,    KC_ESLA,KC_ENLE,KC_RALT
  //                                └───────┴───────┴───────┘   └───────┴───────┴───────┘
    ),
    [_EXTRA] = LAYOUT_split_3x6_3(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_EQSL,KC_MIAL,KC_BSGL,KC_QUCL,KC_GRV ,                    KC_LEFT,KC_DOCR,KC_UPGR,KC_RGAL,KC_RSFT,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_LBRC,KC_CUT ,KC_COPY,KC_PSTE,KC_RBRC,                    KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_INS ,XXXXXXX,
  //└───────┴───────┴───────┴───────┼───────┼───────┼───────┐   ┌───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                                     KC_BSPC,KC_SPLE,KC_TALA,    KC_ESLA,KC_ENLE,XXXXXXX
  //                                └───────┴───────┴───────┘   └───────┴───────┴───────┘
    ),

    [_ADDITIONAL] = LAYOUT_split_3x6_3(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                    KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_LSFT,KC_LALT,KC_LGUI,KC_LCTL,KC_F11 ,                    KC_F12 ,KC_RCTL,KC_RGUI,KC_LALT,KC_RSFT,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLD,KC_VOLU,XXXXXXX,                    XXXXXXX,KC_BRID,KC_BRIU,XXXXXXX,KC_PSCR,XXXXXXX,
  //└───────┴───────┴───────┴───────┼───────┼───────┼───────┐   ┌───────┼───────┼───────┼───────┼───────┴───────┴───────┘
                                     KC_DEL ,KC_SPLE,KC_TALA,    KC_ESLA,KC_ENLE,XXXXXXX
  //                                └───────┴───────┴───────┘   └───────┴───────┴───────┘
    ),
};


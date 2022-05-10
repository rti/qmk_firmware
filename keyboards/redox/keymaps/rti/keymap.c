#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _EXTRA 1
#define _ADDTIONAL 2

// TODO: what is this for?
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EXTRA,
  ADDITIONAL
};

// Shortcut to make keymap more readable
#define EXT_L   MO(_EXTRA)

#define KC_ALBS LALT_T(KC_BSPC)
#define KC_CLES LCTL_T(KC_ESC)
#define KC_GRES RGUI_T(KC_ESC)
#define KC_CTQU RCTL_T(KC_QUOT)
#define KC_GLTA LGUI_T(KC_TAB)
#define KC_CREN RCTL_T(KC_ENT)
#define KC_CLSP LCTL_T(KC_SPC)
#define KC_BR2D HYPR(KC_9)
#define KC_BR2U HYPR(KC_0)

#define KC_A_SL LSFT_T(KC_A)
#define KC_EQSL LSFT_T(KC_EQL)
#define KC_S_AL LALT_T(KC_S)
#define KC_MIAL LALT_T(KC_MINS)
#define KC_D_GL LGUI_T(KC_D)
#define KC_BSGL LGUI_T(KC_BSLS)
#define KC_F_CL LCTL_T(KC_F)
#define KC_QUCL LCTL_T(KC_QUOT)


#define KC_SNSR RSFT_T(KC_SCLN)
#define KC_PSSR RSFT_T(KC_PSCR)
#define KC_L_AL LALT_T(KC_L)
#define KC_RGAL LALT_T(KC_RGHT)
#define KC_K_GR RGUI_T(KC_K)
#define KC_UPGR RGUI_T(KC_UP)
#define KC_J_CR RCTL_T(KC_J)
#define KC_DOCR RCTL_T(KC_DOWN)

#define KC_SPLE LT(_EXTRA, KC_SPC)
#define KC_ENLE LT(_EXTRA, KC_ENT)

#define KC_TALA LT(_ADDTIONAL, KC_TAB)
#define KC_ESLA LT(_ADDTIONAL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_VOLU,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_BRIU,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_VOLD,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,XXXXXXX,                      XXXXXXX,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BRID,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_A_SL,KC_S_AL,KC_D_GL,KC_F_CL,KC_G   ,XXXXXXX,                      XXXXXXX,KC_H   ,KC_J_CR,KC_K_GR,KC_L_AL,KC_SNSR,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,XXXXXXX,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     KC_BSPC,   KC_SPLE,KC_TALA,      KC_ESLA,KC_ENLE,   KC_RALT,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),

  [_EXTRA] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_VOLU,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_BRIU,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_VOLD,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,XXXXXXX,                      XXXXXXX,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BRID,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_EQSL,KC_MIAL,KC_BSGL,KC_QUCL,KC_GRV ,XXXXXXX,                      XXXXXXX,KC_LEFT,KC_DOCR,KC_UPGR,KC_RGAL,KC_PSSR,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_LBRC,KC_CUT ,KC_COPY,KC_PSTE,KC_RBRC,XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     KC_DEL ,   KC_SPLE,KC_TALA,      KC_ESLA,KC_ENLE,   XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),

  [_ADDTIONAL] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,XXXXXXX,                      XXXXXXX,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,   KC_SPLE,KC_TALA,      KC_ESLA,KC_ENLE,   XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),
};

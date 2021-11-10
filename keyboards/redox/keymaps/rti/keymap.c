#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _EXTRA 1
#define _ADJUST 2

// TODO: what is this for?
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EXTRA,
  ADJUST,
};

// Shortcut to make keymap more readable
#define EXT_L   MO(_EXTRA)
#define ADJ_L   MO(_ADJUST)

#define KC_CTES LCTL_T(KC_ESC)
#define KC_CTQU RCTL_T(KC_QUOT)
#define KC_CTEN RCTL_T(KC_ENT)
#define KC_GUSP RGUI_T(KC_SPC)
#define KC_BR2D HYPR(KC_LBRC)
#define KC_BR2U HYPR(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  /* QWERTY - inspired by cykedev
   *,----------------------------------------------.                                         ,----------------------------------------------.
   *|  `~   |   1   |   2   |   3   |   4   |   5  |                                         |   6  |   7   |   8   |   9   |   0   | BSPC  |
   *|-------+-------+-------+-------+-------+------|-------.                         ,-------|------+-------+-------+-------+-------+-------|
   *| Tab   |   Q   |   W   |   E   |   R   |   T  |       |                         |       |   Y  |   U   |   I   |   O   |   P   |  \ |  |
   *|-------+-------+-------+-------+-------+------|-------.                         ,-------|------+-------+-------+-------+-------+-------|
   *|CtlEsc |   A   |   S   |   D   |   F   |   G  |       |                         |       |   H  |   J   |   K   |   L   |  ; :  | Ctl'" |
   *|-------+-------+-------+-------+-------+------|  [ {  |                         |  } ]  |------+-------+-------+-------+-------+-------|
   *| Sh (  |   Z   |   X   |   C   |   V   |   B  |----------------,       ,----------------|   N  |   M   |  , <  |  . >  |  / ?  | Sh )  |
   *|----------------------------------------------/  EXT  / ADJ   /         \  ADJ  \  EXT  \----------------------------------------------|
   *| HYPER |  MEH  |       |       |     /  Alt  /-------/-------/           \-------\-------\  Alt  \     | HOME  | PGDN  | PGUP  | END   |
   *|       |       |       |       |    /       /       /       /             \ Enter \ Space \       \    |       |       |       |       |
   *`-------------------------------'   '-------/  GUI  / CTRL  /               \ CTRL  \ GUI   \-------'   '-------------------------------'
   *                                            '--------------'                 '--------------'
   */
  //┌───────┬───────┬───────┬───────┬────────┬──────┐                                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4    ,KC_5  ,                                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
  //├───────┼───────┼───────┼───────┼────────┼──────┼───────┐                       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R    ,KC_T  ,XXXXXXX,                        XXXXXXX,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
  //├───────┼───────┼───────┼───────┼────────┼──────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_CTES,KC_A   ,KC_S   ,KC_D   ,KC_F    ,KC_G  ,KC_LBRC,                        KC_RBRC,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_CTQU,
  //├───────┼───────┼───────┼───────┼────────┼──────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_LSPO,KC_Z   ,KC_X   ,KC_C   ,KC_V    ,KC_B  ,EXT_L  ,ADJ_L  ,        ADJ_L  ,EXT_L  ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSPC,
  //├───────┼───────┼───────┼───────┼────┬───┴───┬──┼───────┼───────┤       ├───────┼───────┼───┬───┴───┬───┼───────┼───────┼───────┼───────┤
     KC_HYPR,KC_MEH ,XXXXXXX,XXXXXXX,     KC_LALT,   KC_LGUI,KC_LCTL,        KC_CTEN,KC_GUSP,    KC_RALT,    KC_HOME,KC_PGDN,KC_PGUP,KC_END
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘       └───────┴───────┘   └───────┘   └───────┴───────┴───────┴───────┘
  ),

  [_EXTRA] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_DEL ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_PLUS,KC_MINS,KC_EQL ,KC_UNDS,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_AGIN,XXXXXXX,XXXXXXX,KC_FIND,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_UNDO,KC_CUT ,KC_COPY,KC_PSTE,XXXXXXX,_______,XXXXXXX,        XXXXXXX,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤       ├───────┼───────┼───┬───┴───┬───┼───────┼───────┼───────┼───────┤
     _______,_______,XXXXXXX,XXXXXXX,     _______,   _______,_______,        _______,_______,    _______,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘       └───────┴───────┘   └───────┘   └───────┴───────┴───────┴───────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_MUTE,KC_VOLD,KC_VOLU,RGB_TOG,RGB_MOD,                                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PSCR,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,KC_BRID,KC_BRIU,RGB_SAD,RGB_SAI,XXXXXXX,                        _______,KC_PSLS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PMNS,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,XXXXXXX,KC_BR2D,KC_BR2U,RGB_HUD,RGB_HUI,XXXXXXX,                        _______,KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,XXXXXXX,XXXXXXX,XXXXXXX,RGB_VAD,RGB_VAI,XXXXXXX,_______,        _______,XXXXXXX,KC_PCMM,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤       ├───────┼───────┼───┬───┴───┬───┼───────┼───────┼───────┼───────┤
     _______,_______,XXXXXXX,XXXXXXX,     _______,   _______,_______,        _______,_______,    _______,    KC_P0  ,KC_PDOT,KC_PENT,XXXXXXX
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘       └───────┴───────┘   └───────┘   └───────┴───────┴───────┴───────┘
  )
};

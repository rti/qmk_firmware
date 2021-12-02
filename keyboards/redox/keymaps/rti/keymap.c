#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _UML 1
#define _EXTRA 2
#define _ADJUST 3

// TODO: what is this for?
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  UML,
  EXTRA,
  ADJUST,
};

// Shortcut to make keymap more readable
#define UML_L   MO(_UML)
#define EXT_L   MO(_EXTRA)
#define ADJ_L   MO(_ADJUST)

#define KC_ALBS LALT_T(KC_BSPC)
#define KC_CTES LCTL_T(KC_ESC)
#define KC_CTQU RCTL_T(KC_QUOT)
#define KC_GUSP LGUI_T(KC_SPC)
#define KC_GUEN RGUI_T(KC_ENT)
#define KC_BR2D HYPR(KC_LBRC)
#define KC_BR2U HYPR(KC_RBRC)

enum unicode_names {
    ESSZETT,
    AUML,
    AUML_CAPS,
    OUML,
    OUML_CAPS,
    UUML,
    UUML_CAPS,
    EURO,
    TRADEMARK,
    COPYRIGHT,
    ENJE,
    ENJE_CAPS
};

const uint32_t PROGMEM unicode_map[] = {
    [ESSZETT]   = 0x00DF, // ß
    [AUML]      = 0x00E4, // ä
    [AUML_CAPS] = 0x00C4, // Ä
    [OUML]      = 0x00F6, // ö
    [OUML_CAPS] = 0x00D6, // Ö
    [UUML]      = 0x00FC, // ü
    [UUML_CAPS] = 0x00DC, // Ü
    [EURO]      = 0x20AC, // €
    [TRADEMARK] = 0x2122, // ™
    [COPYRIGHT] = 0x00A9, // ©
    [ENJE]      = 0x00F1, // ñ
    [ENJE_CAPS] = 0x00D1, // Ñ
};

#define KC_ESZT X(ESSZETT)
#define KC_AUML XP(AUML, AUML_CAPS)
#define KC_OUML XP(OUML, OUML_CAPS)
#define KC_UUML XP(UUML, UUML_CAPS)
#define KC_EURO X(EURO)
#define KC_TRMA X(TRADEMARK)
#define KC_CPRI X(COPYRIGHT)
#define KC_ENJE XP(ENJE, ENJE_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /****************************************************************************************************************************************
   * QWERTY - inspired by cykedev
   *,-----------------------------------------------.                                     ,-----------------------------------------------.
   *|  `~   |   1   |   2   |   3   |   4   |   5   |                                     |   6   |   7   |   8   |   9   |   0   | BSPC  |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *| Tab   |   Q   |   W   |   E   |   R   |   T   |       |                     |       |   Y   |   U   |   I   |   O   |   P   |  \ |  |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|CtlEsc |   A   |   S   |   D   |   F   |   G   |       |                     |       |   H   |   J   |   K   |   L   |  ; :  | Ctl'" |
   *|-------+-------+-------+-------+-------+-------|  [ {  |                     |  } ]  |-------+-------+-------+-------+-------+-------|
   *| Sh (  |   Z   |   X   |   C   |   V   |   B   |---------------,      ,--------------|   N   |   M   |  , <  |  . >  |  / ?  | Sh )  |
   *|----------------------------------------------/  EXT  / ADJ   /       \  ADJ  \  EXT  \----------------------------------------------|
   *| HYPER |  MEH  |  UML  |       |     / BSPC  /-------/-------/         \-------\-------\  Alt  \     |       |  UML  | MEH   | HYPER |
   *|       |       |       |       |    / Alt   / SPACE /       /           \       \ ENTER \       \    |       |       |       |       |
   *`-------------------------------'   '-------/  GUI  / CTRL  /             \ CTRL  \  GUI  \-------'   '-------------------------------'
   *                                            '--------------'               '--------------'
   */
  [_QWERTY] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                                      KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,XXXXXXX,                      XXXXXXX,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_CTES,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_LBRC,                      KC_RBRC,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_CTQU,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_LSPO,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,EXT_L  ,ADJ_L  ,      ADJ_L  ,EXT_L  ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSPC,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     KC_HYPR,KC_MEH ,UML_L  ,XXXXXXX,     KC_ALBS,   KC_GUSP,KC_LCTL,      KC_RCTL,KC_GUEN,   KC_RALT,     XXXXXXX,UML_L  ,KC_MEH ,KC_HYPR
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),

  /****************************************************************************************************************************************
   * UML
   *,-----------------------------------------------.                                     ,-----------------------------------------------.
   *|       |       |       |       |       |       |                                     |       |       |       |       |       |       |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|       |       |       |   €   |       |   ™   |       |                     |       |       |   Ü   |       |   Ö   |       |       |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|       |   Ä   |   ß   |       |       |       |       |                     |       |       |       |       |       |       |       |
   *|-------+-------+-------+-------+-------+-------|       |                     |       |-------+-------+-------+-------+-------+-------|
   *| SHIFT |       |       |   ©   |       |       |---------------,      ,--------------|   Ñ   |       |       |       |       | SHIFT |
   *|----------------------------------------------/       /       /       \       \       \----------------------------------------------|
   *| HYPER |  MEH  |  UML  |       |     / BSPC  /-------/-------/         \-------\-------\  Alt  \     |       |  UML  |  MEH  | HYPER |
   *|       |       |       |       |    / Alt   / SPACE /       /           \       \ ENTER \       \    |       |       |       |       |
   *`-------------------------------'   '-------/  GUI  / CTRL  /             \ CTRL  \  GUI  \-------'   '-------------------------------'
   *                                            '--------------'               '--------------'
   */
  [_UML] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,XXXXXXX,KC_EURO,XXXXXXX,KC_TRMA,XXXXXXX,                      XXXXXXX,XXXXXXX,KC_UUML,XXXXXXX,KC_OUML,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_AUML,KC_ESZT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_LSFT,XXXXXXX,XXXXXXX,KC_CPRI,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,XXXXXXX,KC_ENJE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_RSFT,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     _______,_______,_______,_______,     _______,   _______,_______,      _______,_______,   _______,     _______,_______,_______,_______
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),

  /****************************************************************************************************************************************
   * EXTRA
   *,-----------------------------------------------.                                     ,-----------------------------------------------.
   *|       |  F1   |  F2   |  F3   |  F4   |  F5   |                                     |  F6   |  F7   |  F8   |  F9   |  F10  |  DEL  |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|       |   +   |   -   |   =   | ????? |       |       |                     |       | HOME  | PGDN  | PGUP  | END   |       |       |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|CtlEsc | REDO  |       |       | FIND  |       |       |                     |       | LEFT  | DOWN  |  UP   | RIGHT |       | Ctl'" |
   *|-------+-------+-------+-------+-------+-------|       |                     |       |-------+-------+-------+-------+-------+-------|
   *| Sh (  | UNDO  |  CUT  | COPY  | PASTE |       |---------------,      ,--------------|       |       |       |       |       | Sh )  |
   *|----------------------------------------------/  EXT  /       /       \       \  EXT  \----------------------------------------------|
   *| HYPER |  MEH  |  UML  |       |     / BSPC  /-------/-------/         \-------\-------\  Alt  \     |       |  UML  |  MEH  | HYPER |
   *|       |       |       |       |    /       / SPACE /       /           \       \ ENTER \       \    |       |       |       |       |
   *`-------------------------------'   '-------/  GUI  / CTRL  /             \ CTRL  \  GUI  \-------'   '-------------------------------'
   *                                            '--------------'               '--------------'
   */
  [_EXTRA] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                      KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_DEL ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,KC_PLUS,KC_MINS,KC_EQL ,KC_UNDS,XXXXXXX,XXXXXXX,                      XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,XXXXXXX,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_AGIN,XXXXXXX,XXXXXXX,KC_FIND,XXXXXXX,XXXXXXX,                      XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_UNDO,KC_CUT ,KC_COPY,KC_PSTE,XXXXXXX,_______,XXXXXXX,      XXXXXXX,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     _______,_______,XXXXXXX,_______,     _______,   _______,_______,      _______,_______,   _______,     _______,XXXXXXX,_______,_______
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),

  /****************************************************************************************************************************************
   * ADJUST
   *,-----------------------------------------------.                                     ,-----------------------------------------------.
   *|       | MUTE  |VOLDOWN| VOLUP |RGB TOG|RGB MOD|                                     |   /   |   7   |   8   |   9   |   -   |PRT SCN|
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|       |       |BR1DOWN| BR1UP |RGB SAD|RGB SAI|       |                     |       |   *   |   4   |   5   |   6   |   +   |       |
   *|-------+-------+-------+-------+-------+-------|-------.                     ,-------|-------+-------+-------+-------+-------+-------|
   *|CtlEsc |       |BR2DOWN| BR2UP |RGB HUD|RGB HUI|       |                     |       |   ,   |   1   |   2   |   3   |   =   | Ctl'" |
   *|-------+-------+-------+-------+-------+-------|       |                     |       |-------+-------+-------+-------+-------+-------|
   *| Sh (  |       |       |       |RGB VAD|RGB VAI|---------------,      ,--------------|       |       |   0   |   .   | ENTER | Sh )  |
   *|----------------------------------------------/       / ADJ   /       \  ADJ  \       \----------------------------------------------|
   *| HYPER |  MEH  |       |       |     /  Alt  /-------/-------/         \-------\-------\  Alt  \     |       |       |       |       |
   *|       |       |       |       |    /       / SPACE /       /           \       \ ENTER \       \    |       |       |       |       |
   *`-------------------------------'   '-------/  GUI  / CTRL  /             \ CTRL  \  GUI  \-------'   '-------------------------------'
   *                                            '--------------'               '--------------'
   */
  [_ADJUST] = LAYOUT(
  //┌───────┬───────┬───────┬───────┬───────┬───────┐                                     ┌───────┬───────┬───────┬───────┬───────┬───────┐
     XXXXXXX,KC_MUTE,KC_VOLD,KC_VOLU,RGB_TOG,RGB_MOD,                                      KC_PSLS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PMNS,KC_PSCR,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐                     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     XXXXXXX,XXXXXXX,KC_BRID,KC_BRIU,RGB_SAD,RGB_SAI,XXXXXXX,                      _______,KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,XXXXXXX,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┤                     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,XXXXXXX,KC_BR2D,KC_BR2U,RGB_HUD,RGB_HUI,XXXXXXX,                      _______,KC_PCMM,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┐     ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,XXXXXXX,XXXXXXX,XXXXXXX,RGB_VAD,RGB_VAI,XXXXXXX,_______,      _______,XXXXXXX,XXXXXXX,XXXXXXX,KC_P0  ,KC_PDOT,KC_PENT,_______,
  //├───────┼───────┼───────┼───────┼────┬──┴────┬──┼───────┼───────┤     ├───────┼───────┼──┬────┴──┬────┼───────┼───────┼───────┼───────┤
     _______,_______,XXXXXXX,_______,     _______,   _______,_______,      _______,_______,   _______,     _______,XXXXXXX,_______,_______
  //└───────┴───────┴───────┴───────┘    └───────┘  └───────┴───────┘     └───────┴───────┘  └───────┘    └───────┴───────┴───────┴───────┘
  ),
};

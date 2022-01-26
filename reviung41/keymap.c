#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"


enum r41_layer {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _SPACE,
    _ARROW,
    _ADJUST
};

enum r41_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DISCO_TOGGLE
};


#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define SPACE  MO(_SPACE)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)

#define LSFT_CAPS  LSFT_T(KC_CAPS)
#define RSFT_ENT   RSFT_T(KC_ENT)
#define RCTL_DQUO  RCTL_T(TR_DQUO)

#define LOWER_UP   LT(LOWER, KC_UP)
#define SPACE_SPC  LT(SPACE, KC_SPC)
#define RAISE_DOWN LT(RAISE, KC_DOWN)
#define ARROW_T    LT(ARROW, KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _COLEMAK  
    * ,----------------------------------------------+          +------------------------------------------------.
    * |   TAB    |  Q   |   W  |   F  |   P  |   G   |          |   J  |   L  |   U  |   Y  |   ;  |     BSPC     |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    * |   LCTRL  |  A   |   R  |   S  |ARRW_T|   D   |          |   H  |   N  |   E  |   I  |   O  |  RCTL_DQUO   |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    * | LSFT_CAPS|LALT_Z|LCTL_X|LSFT_C|   V  |   B   |          |   K  |   M  |RSFT ,|RCTL .|   /  |   RSFT_ENT   |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    *                             | ALT  | Lower_up |  Space_spc  | Raise_down | WIN  |
    *                                 +-------------/             \--------------+
    */

  [_COLEMAK] = LAYOUT_reviung41(
    KC_TAB,     TR_Q,          TR_W,          TR_F,          TR_P,     TR_G,             TR_J,  TR_L,  TR_U,             TR_Y,            TR_SCLN,  KC_BSPC,
    KC_LCTRL,   TR_A,          TR_R,          TR_S,          ARROW_T,  TR_D,             TR_H,  TR_N,  TR_E,             TR_IDOT,         TR_O,     RCTL_DQUO,
    LSFT_CAPS,  LALT_T(TR_Z),  LCTL_T(TR_X),  LSFT_T(TR_C),  TR_V,     TR_B,             TR_K,  TR_M,  RSFT_T(TR_COMM),  RCTL_T(TR_DOT),  TR_SLSH,  RSFT_ENT,
                                                     KC_LALT,   LOWER_UP,     SPACE_SPC,   RAISE_DOWN,    KC_RGUI
  ),

    /* _QWERTY
    * ,----------------------------------------------+          +------------------------------------------------.
    * |    TAB   |   Q  |   W  |   E  |   R  |   T   |          |   Y  |   U  |   İ  |   O  |   P  |     BSPC     |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    * |   LCTRL  |   A  |   S  |   D  |   F  |   G   |          |   H  |   J  |   K  |   L  |   ;  |  RCTL_DQUO   |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    * |LSFT_CAPS |  Z   |   X  |   C  |   V  |   B   |          |   N  |   M  |  ,   | .    |   /  |   RSFT_ENT   |
    * |----------+------+------+------+------+-------+          +------+------+------+------+------+--------------|
    *                             | ALT | Lower_up |  Space_spc  | Raise_down | WIN  |
    *                                 +-------------/             \--------------+
    */


  [_QWERTY] = LAYOUT_reviung41(
    KC_TAB,      TR_Q,  TR_W,  TR_E,  TR_R,  TR_T,                 TR_Y,  TR_U,  TR_IDOT,  TR_O,    TR_P,     KC_BSPC,
    KC_LCTRL,    TR_A,  TR_S,  TR_D,  TR_F,  TR_G,                 TR_H,  TR_J,  TR_K,     TR_L,    TR_SCLN,  RCTL_DQUO,
    LSFT_CAPS,   TR_Z,  TR_X,  TR_C,  TR_V,  TR_B,                 TR_N,  TR_M,  TR_COMM,  TR_DOT,  TR_SLSH,  RSFT_ENT,
                              KC_LALT,   LOWER_UP,    SPACE_SPC,   RAISE_DOWN,    KC_RGUI
  ),
  
   /* _LOWER
    * ,---------------------------------------------------+         +------------------------------------------.
    * |  ESC  |       |       |         |       |         |         |  (   |   )  |   =  |   &  |   |  |  DEL  |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |       |       |       |         |   <   |    >    |         |  {   |   }  |   _  |   $  |   #  |   '   |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |       |       |       |         |       |         |         |  [   |   ]  |   <  |   >  |   \  |  END  |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    *                                    | ____ | ____ |      ENTER     | ____  | ____ |
    *                                    +-------------/                \--------------+
    */


  [_LOWER] = LAYOUT_reviung41(
    KC_ESC,   _______,  _______,   _______,  _______,   _______,               TR_LPRN,  TR_RPRN,   TR_EQL,   TR_AMPR,  TR_PIPE,  KC_DEL,
    _______,  _______,  _______,   _______,  _______,   _______,               TR_LCBR,  TR_RCBR,   TR_UNDS,  TR_DLR,   TR_HASH,  TR_QUOT,
    _______,  _______,  _______,   _______,  _______,   _______,               TR_LBRC,  TR_RBRC,   TR_LABK,  TR_RABK,  TR_BSLS,  KC_END,
                                             _______,   _______,     KC_ENT,    _______,  _______
  ),
 

     /* _RAISE
    * ,---------------------------------------------------+         +------------------------------------------.
    * |  ESC  |   /   |   1   |    2    |   3   |    -    |         |  F1  |  F2  |  F3  |  F4  |      |       |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |       |   *   |   4   |    5    |   6   |    +    |         |  F5  |  F6  |  F7  |  F8  |      |       |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |  HOME |   %   |   7   |    8    |   9   |    0    |         |  F9  |  F10 |  F11  | F12 |      |       |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    *                                   | ____ | ____ |      BSPC     | ____  | ____ |
    *                                   +-------------/               \--------------+
    */
   

  [_RAISE] = LAYOUT_reviung41(
    KC_ESC,   TR_SLSH,  TR_1,  TR_2,  TR_3,  TR_MINS,          KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______,  _______,
    _______,  TR_ASTR,  TR_4,  TR_5,  TR_6,  TR_PLUS,          KC_F5,  KC_F6,   KC_F7,   KC_F8,   _______,  _______,
    KC_HOME,  TR_PERC,  TR_7,  TR_8,  TR_9,  TR_0,             KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,  _______,
                             _______,   _______,     KC_BSPC,    _______,  _______
  ),
 
   /* SPACE
    * ,-------------------------------------------------- -+         +------------------------------------------.
    * |   ESC  |   !    |   @   |    ₺    |   €   |   Ğ    |         |      |      |   Ü  |      |  :   |  DEL  |
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    * |        |        |       |    Ş    |       |   £    |         |      |      | S(ı) |   I  |  Ö   |  `    |
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    * |  LEFT  |        |       |    Ç    |       |        |         |      |      |   ^  |   ~  |   ?  |  RGHT |
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    *                                     | ____ | ____ |     _______      | ____  | ____ |
    *                                     +-------------/                \--------------+
    */


  [_SPACE] = LAYOUT_reviung41(
    KC_ESC,  TR_EXLM,  TR_AT,     TR_LIRA,  TR_EURO,  TR_GBRV,               _______,  _______,  TR_UDIA,   _______,  TR_COLN,  KC_DEL,
    _______,  _______,  _______,  TR_SCED,  _______,  TR_PND,                _______,  _______,  S(TR_I),  TR_I,      TR_ODIA,  TR_GRV,
    KC_LEFT,  _______,  _______,  TR_CCED,  _______,  _______,               _______,  _______,  TR_CIRC,  TR_TILD,   TR_QUES,  KC_RGHT,
                                             _______,   _______,  _______,  _______,  _______
  ),

   /* _ARROW
    * ,---------------------------------------------------+         +------------------------------------------.
    * |       |       |       |         |       |         |         | MPRV | PGUP |  UP  |      |      |       |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |       |       |       |         |       |         |         | HOME | LEFT | DOWN | RGHT | END  | MPLY  |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    * |       |       |       |         |       |         |         | MNXT |PGDOWN|      |VLDOWN| VLUP | MUTE  |
    * |-------+-------+-------+---------+-------+---------+         +------+------+------+------+------+-------|
    *                                    | ____ | ____ |                | ____  | ____ |
    *                                    +-------------/                \--------------+
    */
   
  [_ARROW] = LAYOUT_reviung41(
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,    _______, 
    _______,  _______,  _______,   _______,  _______,   _______,               KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,     KC_MPLY, 
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MNXT,   KC_PGDOWN,  _______,    KC_VOLD,     KC_VOLU,    KC_MUTE, 
                                           _______,   _______,     _______,    _______,  _______ 
  ),





   /* ADJUST
    * ,-------------------------------------------------- -+         +------------------------------------------.
    * |RGB_VAI |RGB_SAI |RGB_HUI|RGB_MOD  |       |RGB_TOG |         |      |      |      |      |QWERTY|COLEMAK|
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    * |RGB_VAD |RGB_SAD |RGB_HUD|RGB_RMOD |       |        |         |      |      |      |      |      |       |
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    * |        |        |       |         |       |D_TOGGLE|         |RESET |      |      |      |      |       |
    * |--------+--------+-------+---------+-------+--------+         +------+------+------+------+------+-------|
    *                                     | ____ | ____ |     _______      | ____  | ____ |
    *                                     +-------------/                \--------------+
    */
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,                 XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QWERTY,   COLEMAK,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   DISCO_TOGGLE,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                   _______,   _______,  XXXXXXX,  _______,  _______
  ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool disco_mode_enabled = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
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
    case DISCO_TOGGLE:
      if (record->event.pressed) {
        disco_mode_enabled ^= 1;
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom(0, 0, 0);
      }
      return false;
      break;
  }
  return true;
}



uint8_t left_hue;
uint8_t right_hue;
uint8_t left_value;
uint8_t right_value;
uint16_t animation_timer;

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (disco_mode_enabled) {
    if (record->event.pressed) {
      if (record->event.key.row > 2) {
        left_hue = rand() % 255;
        left_value = 255;
        rgblight_sethsv_range(left_hue, 255, left_value,
          5, 5);
      } else {
        right_hue = rand() % 255;
        right_value = 255;
        rgblight_sethsv_range(right_hue, 255, right_value,
          0, 5);
      }
    }
  }
}

void matrix_init_user(void) {
  animation_timer = timer_read();
}

#define CUBIC_EASE(x) ((uint32_t)(x) * (x) * (x) / 255 / 255)
void matrix_scan_user(void) {
  if (
    disco_mode_enabled &&
    (left_value > 0 || right_value > 0) &&
    timer_elapsed(animation_timer) > 20
  ) {
    animation_timer = timer_read();

    if (left_value > 0) {
      left_value -= 5;
      rgblight_sethsv_range(left_hue, 255, CUBIC_EASE(left_value),
      5, 9);
    }

    if (right_value > 0) {
      right_value -= 5;
      rgblight_sethsv_range(right_hue, 255, CUBIC_EASE(right_value),
      0, 5);
    }
  }
}
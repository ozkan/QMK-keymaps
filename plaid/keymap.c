#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"

enum plaid_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _SPACE,
  _NAVIGATION,
  _PLOVER,
  _ADJUST
};

enum plaid_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  PLOVER,
  EXT_PLV,
  LED_1,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_0
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPACE MO(_SPACE)
#define NAV   MO(_NAVIGATION)

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
    KC_LCTL,
    KC_RCTL,
    KC_LALT,
    KC_RALT,
    KC_LSFT,
    KC_RSFT,
    KC_LGUI,
    KC_RGUI,
    LOWER,
    RAISE
};

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

#define SPACE_SPC  LT(SPACE, KC_SPC)
#define LSFT_CAPS  LSFT_T(KC_CAPS)
#define NAV_T      LT(NAV, KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |NAV_T |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|LALT Z|LCTL X|LSFT C|   V  |   B  |   K  |   M  |RSFT ,|RCFT .|LALT /|Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_plaid_grid(
    KC_TAB,    KC_Q,          KC_W,          KC_F,            KC_P,       KC_G,       KC_J,       KC_L,    KC_U,             KC_Y,            TR_SCLN,    KC_BSPC,
    KC_ESC,    KC_A,          KC_R,          KC_S,            NAV_T,      KC_D,       KC_H,       KC_N,    KC_E,             TR_IDOT,         KC_O,       TR_DQUO,
    KC_LCTL,   LALT_T(TR_Z),  LCTL_T(TR_X),  LSFT_T(TR_C),    KC_V,       KC_B,       KC_K,       KC_M,    RSFT_T(TR_COMM),  RCTL_T(TR_DOT),  LALT_T(TR_SLSH),    KC_ENT ,
    LSFT_CAPS, KC_RALT,       KC_LALT,       KC_LGUI,         LOWER,      SPACE_SPC,  SPACE_SPC,  RAISE,   KC_LEFT,          KC_UP,           KC_DOWN,    KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,       KC_U,    TR_IDOT,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,       KC_J,    KC_K,    KC_L,    TR_SCLN, TR_QUOT,
    KC_LCTL,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,       KC_M,    TR_COMM, TR_DOT,  TR_SLSH, KC_ENT ,
    LSFT_CAPS,   KC_RALT, KC_LALT, KC_LGUI, LOWER,   SPACE_SPC,  SPACE_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_plaid_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   (  |   )  |   =  |   &  |   |  |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   {  |   }  |   _  |   $  |   #  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   [  |  ]   |   <  |   >  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    ENTER     |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    _______,  _______,  _______,   _______,   _______,   _______,   TR_LPRN,  TR_RPRN,   TR_EQL,   TR_AMPR,  TR_PIPE,  KC_DEL,
    _______,  _______,  _______,   _______,   _______,   _______,   TR_LCBR,  TR_RCBR,   TR_UNDS,  TR_DLR,   TR_HASH,  TR_QUOT,
    _______,  _______,  _______,   _______,   _______,   _______,   TR_LBRC,  TR_RBRC,   TR_LABK,  TR_RABK,  TR_BSLS,  KC_END,
    _______,  _______,  _______,   _______,   _______,   KC_ENT,    KC_ENT,   _______,   KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   /  |   1  |   2  |   3  |   -  |  F1  |  F2  |  F3  |  F4  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  *   |   4  |   5  |   6  |   +  |  F5  |  F6  |  F7  |  F8  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  %   |   7  |   8  |   9  |   0  |  F9  |  F10 |  F11 |  F12 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    BSPC     |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    _______,  TR_SLSH,   TR_1,     TR_2,    TR_3,    TR_MINS,     KC_F1,    KC_F2,     KC_F3,     KC_F4,    _______,   _______,
    _______,  TR_ASTR,   TR_4,     TR_5,    TR_6,    TR_PLUS,     KC_F1,    KC_F2,     KC_F3,     KC_F4,    _______,   _______,
    _______,  TR_PERC,   TR_7,     TR_8,    TR_9,    TR_0,        KC_F9,    KC_F10,    KC_F11,    KC_F12,   _______,   _______,
    _______,  _______,   _______,  _______, _______, KC_BSPC,     KC_BSPC,  _______,   KC_MNXT,   KC_VOLD,  KC_VOLU,   KC_MPLY
), 

/* Space
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   €  |   £  |   ğ  |       |      |  ü   |  ı   |     |  del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  !   |  @   |   ş  |   ₺  |     | LEFT |  UP  |  DWN | RGHT |   ö   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACE] = LAYOUT_plaid_grid(
    _______,  _______,  _______,   TR_EURO,   TR_PND,    TR_GBRV,   _______,   _______,  TR_UDIA,    _______,   TR_COLN,   KC_DEL,
    _______,  TR_EXLM,  TR_AT,     TR_SCED,   TR_LIRA,   _______,   _______,   _______,  S(TR_I),    TR_I,      TR_ODIA,   TR_GRV,
    _______,  _______,  _______,   TR_CCED,   _______,   _______,   _______,   _______,  TR_CIRC,    TR_TILD,   TR_QUES,   KC_RGHT,
    _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______
),  


/* navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | MPRV | PGUP |  UP  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | HOME | LEFT | DOWN | RGHT | END  | MPLY |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | MNXT |PGDOWN|      |VLDOWN| VLUP | MUTE |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION] = LAYOUT_plaid_grid(
    _______,  _______,  _______,   _______,   _______,    _______,   KC_MPRV,  KC_PGUP,   KC_UP,      _______,   _______,   _______,
    _______,  _______,  _______,   _______,   _______,    _______,   KC_HOME,  KC_LEFT,   KC_DOWN,    KC_RGHT,   KC_END,    KC_MPLY,
    _______,  _______,  _______,   _______,   _______,    _______,   KC_MNXT,  KC_PGDOWN,  _______,   KC_VOLD,   KC_VOLU,   KC_MUTE,
    _______,  _______,  _______,   _______,   _______,    _______,   _______,  _______,    _______,   _______,   _______,   _______
), 

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_plaid_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |Plover|Dvorak|Qwerty|Colemk|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    RESET,   LED_1,   LED_2,   LED_3,   LED_4,   LED_5,   LED_6,   LED_7,    LED_8,  LED_9,   LED_0,   KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  PLOVER, DVORAK,  QWERTY,  COLEMAK,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
)


};

//Setup config struct for LED
typedef union {
  uint32_t raw;
  struct {
    uint8_t  red_mode :8;
    uint8_t  green_mode :8;
  };
} led_config_t;
led_config_t led_config;

//Set leds to saved state during powerup
void keyboard_post_init_user(void) {
  // set LED pin modes
  setPinOutput(LED_RED);
  setPinOutput(LED_GREEN);

  // Call the post init code.
  led_config.raw = eeconfig_read_user();

  if(led_config.red_mode == LEDMODE_ON) {
      writePinHigh(LED_RED);
  }

  if(led_config.green_mode == LEDMODE_ON) {
      writePinHigh(LED_GREEN);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset! 
  led_config.raw = 0;
  led_config.red_mode = LEDMODE_ON;
  led_config.green_mode = LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
  eeconfig_update_user(led_config.raw);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
    switch (led_mode) {
      case LEDMODE_MODS:
        for (int i=0;i<sizeof(modifiers) / sizeof(modifiers[0]);i++) {
          if(keycode==modifiers[i]) {
            if (record->event.pressed) {
              writePinHigh(led);
            }
            else {
              writePinLow(led);
            }
          }
        }
        break;
      case LEDMODE_BLINKIN:
        if (record->event.pressed) {
          if(rand() % 2 == 1) {
            if(rand() % 2 == 0) {
              writePinLow(led);
            }
            else {
              writePinHigh(led);
            }
          }
        }
        break;
      case LEDMODE_KEY:
        if (record->event.pressed) {
          writePinHigh(led);
          return;
        }
        else {
          writePinLow(led);
          return;
        }
        break;
      case LEDMODE_ENTER:
        if (keycode==KC_ENT) {
          writePinHigh(led);
        }
        else {
          writePinLow(led);
        }
        break;

    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* If the either led mode is keypressed based, call the led updater
     then let it fall through the keypress handlers. Just to keep 
     the logic out of this procedure */
  if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_RED, led_config.red_mode, keycode, record);
  }
  if (led_config.green_mode >= LEDMODE_MODS && led_config.green_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_GREEN, led_config.green_mode, keycode, record);
  }
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
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
    case LED_1:
      if (record->event.pressed) {
        if (led_config.red_mode==LEDMODE_ON) {
            led_config.red_mode=LEDMODE_OFF;
            writePinLow(LED_RED);
        }
        else {
            led_config.red_mode=LEDMODE_ON;
            writePinHigh(LED_RED);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_2:
      if (record->event.pressed) {
        if (led_config.green_mode==LEDMODE_ON) {
            led_config.green_mode=LEDMODE_OFF;
            writePinLow(LED_GREEN);
        }
        else {
            led_config.green_mode=LEDMODE_ON;
            writePinHigh(LED_GREEN);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_3:
      led_config.red_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_4:
      led_config.green_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_5:
      led_config.red_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_6:
      led_config.green_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_7:
      led_config.red_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_8:
      led_config.green_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_9:
      led_config.red_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_0:
      led_config.green_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
  }
  return true;
}

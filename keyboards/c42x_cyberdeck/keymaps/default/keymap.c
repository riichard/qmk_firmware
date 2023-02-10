#include QMK_KEYBOARD_H

#define _BASE 0 // BASE LAYER
#define _NAV 1
#define _NUMERIC 2

#define MOUSEKEY_INITIAL_SPEED 50
#define MOUSEKEY_BASE_SPEED 400
#define MOUSEKEY_MOVE_DELTA 5

#define ONESHOT_TAP_TOGGLE 1
#define ONESHOT_TIMEOUT 500

const key_override_t prev_left_override = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_LEFT);
const key_override_t next_right_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_RIGHT);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &prev_left_override,
    &next_right_override,
    NULL
};


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
    KC_ESC,                                                              KC_F5,
    KC_TAB,                                                              KC_F6,
    OSM(MOD_LALT),                                                              KC_F7,
    OSM(MOD_LCTL),                                                              TG(_NUMERIC),

    KC_ENTER,   TG(_NAV),   KC_UP,  KC_DOWN,    OSM(MOD_LSFT),    KC_F12,     KC_F13,     KC_WH_U,    KC_WH_D,
    KC_A,       KC_B,       KC_C,   KC_D,       KC_E,       KC_F,       KC_ACL0,    KC_MS_U,    KC_BTN2,
    KC_G,       KC_H,       KC_I,   KC_J,       KC_K,       KC_L,       KC_MS_L,    KC_BTN1,    KC_MS_R,
    KC_M,       KC_N,       KC_O,   KC_P,       KC_Q,       KC_R,       KC_ACL1,    KC_MS_D,    KC_9,
                KC_S,       KC_T,   KC_U,       KC_V,       KC_W,       KC_DOT,     KC_0,
                KC_X,       KC_Y,   KC_Z,       KC_BSPC,    KC_ESC,     KC_SPC,     KC_SLSH
    ),

[_NAV] = LAYOUT(
    A(KC_1),                                                     A(KC_5),
    A(KC_2),                                                     A(KC_6),
    A(KC_3),                                                     A(KC_7),
    A(KC_4),                                                     _______,

    _______,_______,_______,_______,_______,_______,_______,KC_WH_U,KC_WH_D,
    _______,_______,_______,_______,_______,_______,_______,KC_MS_U,KC_BTN2,
    _______,_______,_______,_______,_______,_______,KC_MS_L,KC_BTN1,KC_MS_R,
    _______,_______,_______,_______,_______,_______,_______,KC_MS_D,_______,
            _______,_______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,_______
    ),

[_NUMERIC] = LAYOUT(
    _______,                                                     _______,
    _______,                                                     _______,
    _______,                                                     _______,
    _______,                                                     _______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,KC_1,   KC_2,   KC_3,
    _______,_______,_______,_______,_______,_______,KC_4,   KC_5,   KC_4,
    _______,_______,_______,_______,_______,_______,KC_7,   KC_8,   KC_9,
            _______,_______,_______,_______,_______,_______,KC_0,
            _______,_______,_______,_______,_______,_______,_______
    )
};
2
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}

void keyboard_pre_init_user(void) {
    setPinOutput(LINE_PIN27); // OFFSET
    setPinOutput(LINE_PIN28); // DGRAD
    setPinOutput(LINE_PIN29); // DR
    setPinOutput(LINE_PIN30); // DSPLY
    setPinOutput(LINE_PIN31); // APRCH
    setPinOutput(LINE_PIN32); // MSG
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uprintf("Layer: %u\n", get_highest_layer(state));
    switch (get_highest_layer(state)) {
        case _NAV:
            writePinHigh(LINE_PIN30);
            break;
        case _NUMERIC:
            writePinHigh(LINE_PIN28);
            break;
        default:
            writePinLow(LINE_PIN28);
            writePinLow(LINE_PIN30);
            break;
    }
    return state;
}

/*
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        case KC_SPC:
            return false;

        default:
            return true;  // Deactivate Caps Word.
    }
}
*/

void caps_word_set_user(bool active) {
    if (active) {
        uprint("Caps word on");
        writePinHigh(LINE_PIN37);
        // Do something when Caps Word activates.
    } else {
        uprint("Caps word off");
        writePinLow(LINE_PIN37);
        // Do something when Caps Word deactivates.
    }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot mods SHIFT");
    writePinHigh(LINE_PIN27);
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot mods CTRL");
    writePinHigh(LINE_PIN31);
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot mods ALT");
    writePinHigh(LINE_PIN29);
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot mods GUI");
  }
  if (!mods) {
    println("Oneshot mods off");
    writePinLow(LINE_PIN27);
    writePinLow(LINE_PIN29);
    writePinLow(LINE_PIN31);
  }
}

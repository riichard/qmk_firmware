#include QMK_KEYBOARD_H

#define BASE 0 // BASE LAYER


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
[BASE] = LAYOUT(
    KC_F1,                                                              KC_F5,
    KC_F2,                                                              KC_F6,
    KC_F3,                                                              KC_F7,
    KC_F4,                                                              KC_F8,

    KC_ENTER,   KC_F10, KC_UP,  KC_DOWN,    KC_LSFT,    KC_F12,     KC_F13,     KC_WH_U,    KC_WH_D,
    KC_A,       KC_B,   KC_C,   KC_D,       KC_E,       KC_F,       KC_ACL0,    KC_MS_U,    KC_BTN2,
    KC_G,       KC_H,   KC_I,   KC_J,       KC_K,       KC_L,       KC_MS_L,    KC_BTN1,    KC_MS_R,
    KC_M,       KC_N,   KC_O,   KC_P,       KC_Q,       KC_R,       KC_ACL1,    KC_MS_D,    KC_9,
                KC_S,   KC_T,   KC_U,       KC_V,       KC_W,       KC_DOT,     KC_0,
                KC_X,   KC_Y,   KC_Z,       KC_BSPC,    KC_ESC,     KC_SPC,     KC_SLSH
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

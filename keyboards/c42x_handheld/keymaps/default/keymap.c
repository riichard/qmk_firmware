
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,
        KC_F,   KC_G,   KC_H,   KC_I,   KC_J,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,
        KC_P,   KC_O,   KC_R,   KC_S,   KC_T,
        KC_U,   KC_V,   KC_W,   KC_X,   KC_Y
    )
};

#include QMK_KEYBOARD_H
#include "print.h"



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


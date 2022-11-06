/* Copyright 2020 QMK
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

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS               \
    {                                 \
        LINE_PIN23,     /* ROW_1  = 1  */   \
        LINE_PIN22,     /* ROW_2  = 3  */   \
        LINE_PIN2,      /* ROW_3  = 4  */   \
        LINE_PIN3,      /* ROW_4  = 6  */   \
        LINE_PIN4,      /* ROW_5  = 8  */   \
        LINE_PIN7,      /* ROW_6  = 14 */   \
        LINE_PIN8,      /* ROW_7  = 18 */   \
        LINE_PIN15      /* ROW_8  = 33 */   \
    }

#define MATRIX_COL_PINS             \
    {                               \
        LINE_PIN21,     /* COL_0  = 9 */ \
        LINE_PIN5,      /* COL_1  = 10 */ \
        LINE_PIN20,     /* COL_2  = 11 */ \
        LINE_PIN6,      /* COL_3  = 12 */ \
        LINE_PIN19,     /* COL_4  = 13 */ \
        LINE_PIN18,     /* COL_5  = 15 */ \
        LINE_PIN9,      /* COL_6  = 20 */ \
        LINE_PIN10,     /* COL_7  = 22 */ \
        LINE_PIN17,     /* COL_8  = 23 */ \
        LINE_PIN16,     /* COL_9  = 25 */ \
        LINE_PIN11      /* COL_10 = 26 */ \
    }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Well-worn Cherry MX key switches can bounce for up to 20ms, despite the
 * Cherry data sheet specifying 5ms. Because we use the sym_eager_pk debounce
 * algorithm, this debounce latency only affects key releases (not key
 * presses). */
#undef DEBOUNCE
#define DEBOUNCE 20

#define IGNORE_MOD_TAP_INTERRUPT

// The Teensy 4.1 consumes about 100 mA of current at its full speed of 600 MHz
// as per https://www.pjrc.com/store/teensy41.html
#define USB_MAX_POWER_CONSUMPTION 100

/* We use the i.MX RT1060 high-speed GPIOs (GPIO6-9) which are connected to the
 * AHB bus (AHB_CLK_ROOT), which runs at the same speed as the ARM Core Clock,
 * i.e. 600 MHz. See MIMXRT1062, page 949, 12.1 Chip-specific GPIO information.
 * No additional delay is necessary. */

// in clock cycles
#define GPIO_INPUT_PIN_DELAY 0

#define LED_PIN_ON_STATE 37
/*
#define LED_NUM_LOCK_PIN LINE_PIN26
#define LED_CAPS_LOCK_PIN LINE_PIN12
#define LED_SCROLL_LOCK_PIN LINE_PIN25
#define LED_COMPOSE_PIN LINE_PIN24
*/

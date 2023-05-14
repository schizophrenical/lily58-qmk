/*
Lily58 Keymap.

Features:
- Mod-Tap
-- CTRL/ESC
-- LSFT/CAPS
- Encoder on the right hand side.
- Custom OLED display.
-- Left: Status (Layer, WPM, CAPS)
-- Right: Bongo Cat animation.
*/

#include QMK_KEYBOARD_H

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *  QWERTY
 *
 *  ╭────────┬────────┬────────┬────────┬────────┬────────╮                         ╭────────┬────────┬────────┬────────┬────────┬────────╮
 *  ├    `   ┼   1    ┼   2    ┼   3    ┼   4    ┼   5    ┤                         ├   6    ┼   7    ┼   8    ┼   9    ┼   0    ┼    ~   ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   TAB  ┼   Q    ┼   W    ┼   E    ┼   R    ┼   T    ┤                         ├   Y    ┼   U    ┼   I    ┼   O    ┼   P    ┼  DEL   ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   ESC  ┼   A    ┼   S    ┼   D    ┼   F    ┼   G    ┤ ╭─────────╮ ╭─────────╮ ├   H    ┼   J    ┼   K    ┼   L    ┼   ;    ┼    '   ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤ ├         ┤ ├         ┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├  SHIFT ┼   Z    ┼   X    ┼   C    ┼   V    ┼   B    ┤ ╰─────────╯ ╰─────────╯ ├   N    ┼   M    ┼   ,    ┼   .    ┼   /    ┼  ENT   ┤
 *  ╰────────┴────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┴────────╯
 *                             ├  ALT   ┼  GUI   ┼ LOWER  ┤ ╭─────────╮ ╭─────────╮ ├ RAISE  ┼  MENU  ┼ RCTRL  ┤
 *                             ╰────────┴────────┴────────╯ ├  SPACE  ┤ ├  BKSPC  ┤ ╰────────┴────────┴────────╯
 *                                                          ╰─────────╯ ╰─────────╯
 *
 */
[_QWERTY] = LAYOUT(
  KC_GRV,         KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
  KC_TAB,         KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  LCTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  LSFT_T(KC_CAPS),KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                          KC_LALT, KC_LGUI,  MO(_LOWER),   KC_SPC,  KC_BSPC, MO(_RAISE), KC_MENU, KC_RCTL
),

/*
 *  LOWER
 *
 *  ╭────────┬────────┬────────┬────────┬────────┬────────╮                         ╭────────┬────────┬────────┬────────┬────────┬────────╮
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤                         ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   F1   ┼   F2   ┼   F3   ┼   F4   ┼   F5   ┼   F6   ┤                         ├   F7   ┼   F8   ┼   F9   ┼   F10  ┼   F11  ┼  F12   ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   `    ┼   !    ┼   @    ┼   #    ┼   $    ┼   %    ┤ ╭─────────╮ ╭─────────╮ ├   ^    ┼   &    ┼   *    ┼   (    ┼   )    ┼   ~    ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤ ├         ┤ ├         ┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤ ╰─────────╯ ╰─────────╯ ├        ┼   _    ┼   =    ┼   {    ┼   }    ┼   |    ┤
 *  ╰────────┴────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┴────────╯
 *                             ┼        ┼        ┼        ┤ ╭─────────╮ ╭─────────╮ ┼        ┼        ┼        ┤
 *                             ╰────────┴────────┴────────╯ ├         ┤ ├         ┤ ╰────────┴────────┴────────╯
 *                                                          ╰─────────╯ ╰─────────╯
 *
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 *  RAISE
 *
 *  ╭────────┬────────┬────────┬────────┬────────┬────────╮                         ╭────────┬────────┬────────┬────────┬────────┬────────╮
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤                         ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   `    ┼   1    ┼   2    ┼   3    ┼   4    ┼   5    ┤                         ├   6    ┼   7    ┼   8    ┼   9    ┼   0    ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   F1   ┼   F2   ┼   F3   ┼   F4   ┼   F5   ┼   F6   ┤ ╭─────────╮ ╭─────────╮ ├  LEFT  ┼  DOWN  ┼   UP   ┼ RIGHT  ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤ ├         ┤ ├         ┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├   F7   ┼   F8   ┼   F9   ┼   F10  ┼   F11  ┼  F12   ┤ ╰─────────╯ ╰─────────╯ ├        ┼   -    ┼   +    ┼   [    ┼   ]    ┼   /    ┤
 *  ╰────────┴────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┴────────╯
 *                             ┼        ┼        ┼        ┤ ╭─────────╮ ╭─────────╮ ┼        ┼        ┼        ┤
 *                             ╰────────┴────────┴────────╯ ├         ┤ ├         ┤ ╰────────┴────────┴────────╯
 *                                                          ╰─────────╯ ╰─────────╯
 *
 */
 [_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   LCTL(LALT(KC_DEL)),   _______,  KC_PLUS, KC_MINS, KC_PLUS,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______,             _______,  _______, _______, _______
),

/*
 *  ADJUST
 *
 *  ╭────────┬────────┬────────┬────────┬────────┬────────╮                         ╭────────┬────────┬────────┬────────┬────────┬────────╮
 *  ├UC_WINC ┼UC_LINX ┼        ┼        ┼        ┼        ┤                         ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤                         ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤ ╭─────────╮ ╭─────────╮ ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ├────────┼────────┼────────┼────────┼────────┼────────┤ ├         ┤ ├         ┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
 *  ├        ┼        ┼        ┼        ┼        ┼        ┤ ╰─────────╯ ╰─────────╯ ├        ┼        ┼        ┼        ┼        ┼        ┤
 *  ╰────────┴────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┴────────╯
 *                             ├        ┼        ┼        ┤ ╭─────────╮ ╭─────────╮ ├        ┼        ┼        ┤
 *                             ╰────────┴────────┴────────╯ ├         ┤ ├         ┤ ╰────────┴────────┴────────╯
 *                                                          ╰─────────╯ ╰─────────╯
 *
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_QWERTY)){
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  } else if (IS_LAYER_ON(_LOWER)){
    if (clockwise) {
      tap_code(KC_RIGHT);
    } else {
      tap_code(KC_LEFT);
    }
  }

  return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop.
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void draw_bongo_cat(void);

// Write to OLED
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(" || -=+ Lily58 +=-", false);
    // Layer state
    if (IS_LAYER_ON(_QWERTY)){
      oled_write_ln(" || - Layer: QWERTY", false);
    } else if (IS_LAYER_ON(_LOWER)){
      oled_write_ln(" || - Layer: SYMBOLS", false);
    } else if (IS_LAYER_ON(_RAISE)){
      oled_write_ln(" || - Layer: FUNCTION KEYS", false);
    } else {
      oled_write_ln(" || - Layer: ADJUST", false);
    }
    // WPM
    oled_write(" || - WPM: ", false);
    oled_write_ln(get_u8_str(get_current_wpm(), '0'), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln(led_state.caps_lock ? " || - CAPS: ON " : " || - CAPS: OFF", false);
  } else {
    // Draw bongo cat on slave side.
    draw_bongo_cat();
  }

  return false;
}


#endif // OLED_ENABLE

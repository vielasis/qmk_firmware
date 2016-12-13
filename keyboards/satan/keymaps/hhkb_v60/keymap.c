#include "satan.h"

// Layer Names
#define _MAIN_LAYER 0
#define _OVERLAY_LAYER 1
#define _ARROW_LAYER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // http://www.keyboard-layout-editor.com/#/gists/4e4e04dc0e71758968eb51c172b06ddc
    [_MAIN_LAYER] = KEYMAP_TKG(
        F(0),1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,F(1),RSFT, \
        CAPS,LGUI,LALT,          SPC,                GRV, RALT,RGUI,APP, RCTL),
    [_OVERLAY_LAYER] = KEYMAP_TKG(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, ____, \
        ____,____,UP,  ____,____,____,____,____,____,____,____,____,____,____, \
        ____,LEFT,DOWN,RGHT,____,____,____,____,____,____,____,____,     F(2), \
        ____,     ____,____,____,____,____,____,____,____,____,____,F(1), UP,  \
        ____,____,____,          ____,               PSCR,____,LEFT,DOWN,RGHT),
    [_ARROW_LAYER] = KEYMAP_TKG(
        ____,____,____,____,____,____,____,____,____,____,____,____,____,____, \
        ____,____,____,____,____,____,____,____,____,____,____,____,____,____, \
        ____,____,____,____,____,____,____,____,____,____,____,____,     ____, \
        ____,     ____,____,____,____,____,____,____,____,____,____,____, UP,  \
        ____,____,____,          ____,               ____,____,LEFT,DOWN,RGHT),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(SHIFT_ESC),
  [1] = ACTION_LAYER_MOMENTARY(1),
  [2] = ACTION_LAYER_TOGGLE(2)
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
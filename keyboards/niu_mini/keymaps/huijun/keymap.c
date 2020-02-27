#include QMK_KEYBOARD_H

enum layers {
  _TYPE,
  _CTRL,
  _NUMB,
  _RGBC
};

#define LOWER MO(_CTRL)
#define RAISE MO(_NUMB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_TYPE] = LAYOUT_ortho_4x12(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_CTRL] = LAYOUT_ortho_4x12(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,  _______, _______, _______, _______, _______, _______, KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, _______, _______, _______, _______, S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
        RESET,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [_NUMB] = LAYOUT_ortho_4x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [_RGBC] = LAYOUT_ortho_4x12(
            _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 1}; // Set the last one to 10ms for some speedy swirls

uint8_t prev = _TYPE;
uint32_t check;
uint32_t desired = 21;

void matrix_init_user(void) {
    rgblight_mode(desired);
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_RGBC) {
	  switch (layer) {
		case _TYPE:
		  rgblight_mode(desired);
		  break;

		case _CTRL: // If we're in swirl mode, then speed up the swirls, otherwise breathe
		  check = rgblight_get_mode();
		  if (check > 8 && check < 15) {
			rgblight_mode(14);
		  } else {
			rgblight_mode(5);
		  }
		  break;

		case _NUMB: // Same as above but reverse direction, otherwise nightrider
		  check = rgblight_get_mode();
		  if (check > 8 && check < 15) {
			rgblight_mode(13);
		  } else {
			rgblight_mode(23);
		  }
		  break;

		case _RGBC:
		  break;
	  }
  } else {
	  desired = rgblight_get_mode();
  }
  prev = layer;
  return update_tri_layer_state(state, _CTRL, _NUMB, _RGBC);
}

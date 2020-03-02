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

uint8_t prev = _TYPE;
#define RGBLIGHT_ANIMATIONS
// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};
// How long (in milliseconds) to wait between animation steps for each of the "Cycling rainbow" animations
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};
// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};
// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};
// How long (in milliseconds) to wait between animation steps for each of the "Knight" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};
// These control which hues are selected for each of the "Static gradient" modes
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 170, 127, 85, 64};

void default_mode(void) {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_orange();
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void keyboard_post_init_user(void) {
    default_mode();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _CTRL, _NUMB, _RGBC);
    switch (biton32(state)) {
        case _TYPE:
            default_mode();
            break;

        case _CTRL:
            rgblight_mode(RGBLIGHT_MODE_KNIGHT);
            break;

        case _NUMB:
            rgblight_mode(RGBLIGHT_MODE_SNAKE);
            break;

        case _RGBC:
            rgblight_mode(RGBLIGHT_MODE_CHRISTMAS);
            break;

        default:
            default_mode();
            break;
        }
    return state;
}

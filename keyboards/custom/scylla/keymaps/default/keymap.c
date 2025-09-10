#include QMK_KEYBOARD_H

#define BASE DF(_BASE)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define SYSTEM DF(_SYSTEM)

enum layers {
   _BASE,
   _RAISE,
   _LOWER,
   _SYSTEM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
   /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Del  |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | Shft |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  / LOWER /---------------.    .---------------\ RAISE \
   *                                 /       / Enter /  Del  /      \  Bsp  \ Space \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /  Alt  / Ctrl  /            \  Ctrl \  Alt  \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
   KC_DEL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_LSFT,
                                                KC_ENTER , KC_LCTL , LOWER , RAISE , KC_RCTL , KC_SPC,
                                                         KC_DEL , KC_LALT , KC_RALT , KC_BSPC
    ),

   [_RAISE] = LAYOUT(
   /* RAISE
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |   [  |   ]  |      |                                  |   $  |   /  |  *   |  #   |   ~  |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |  Ins |  !   |  @   |   (  |   )  |      |                                  |   %  |   -  |  +   |  =   |  ?   |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |   {  |   }  |      |                                  |   ^  |   &  |  |   |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                                     KC_DLR , KC_SLSH, KC_ASTR, KC_HASH, KC_TILD, KC_F12 ,
   KC_INS , KC_EXLM, KC_AT  , KC_LPRN, KC_RPRN, XXXXXXX,                                     KC_PERC, KC_MINS, KC_PPLS, KC_PEQL, KC_QUES, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                                     KC_CIRC, KC_AMPR, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______, _______, _______, _______, _______,
                                                         _______, _______, _______, _______
    ),

   [_LOWER] = LAYOUT(
   /* LOWER
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |   [  |   ]  |  +   |                                  |      |      |      |      |      |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |  Ins |  !   |  @   |   (  |   )  |  -   |                                  |      | left | down |  up  | rght |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |   {  |   }  |  =   |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PPLS,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12 ,
   KC_INS , KC_EXLM, KC_AT  , KC_LPRN, KC_RPRN, KC_MINS,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PEQL,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______, _______, _______, _______, _______,
                                                         _______, _______, _______, _______
   ),

   [_SYSTEM] = LAYOUT(
   /* SYSTEM
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | BASE |      |      |      |      | BASE |                                  | BASE |      |      |      |      | BASE |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |  V+  |                                  |  B + |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |  V-  |                                  |  B - | ms_l | ms_d | ms_u | ms_r |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      | Mute |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   BASE   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BASE   ,                                     BASE   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BASE   ,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                                     KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                                     KC_BRID, MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _SYSTEM);
}

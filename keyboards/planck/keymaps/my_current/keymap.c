#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

enum planck_layers {
  _BASE,
  _SYMBOLS,
  _NUMERIC,
  _FUNC,
  _NUMPAD
};

// layer toggle aliases...
#define _SYM MO(_SYMBOLS)           // hold for symbol layer...
#define _NUM MO(_NUMERIC)           // hold for numeric layer...
#define _FNC LT(_FUNC, KC_TAB)      // hold for function layer, tap for tab...
#define _NPD MO(_NUMPAD)           // hold for numeric layer...

// main function aliases...
#define XCTL LCTL_T(KC_ESC)         // hold for ctrl, tap for escape...
#define BKSP KC_BSPC                // backspace...
#define ENTR KC_ENT                 // enter...
#define SHFT KC_LSFT                // left shift...
#define DEL_ KC_DEL                 // delete...
#define CTRL KC_LCTL                // left control...
#define SUPR KC_LGUI                // super modifier...
#define ALT_ KC_LALT                // left alt...
#define SPC_ KC_SPC                 // space...
#define UP__ KC_UP                  // up arrow...
#define DN__ KC_DOWN                // down arrow...
#define LT__ KC_LEFT                // left arrow...
#define RT__ KC_RIGHT               // right arrow...
#define TAB_ KC_TAB                 // tab...
#define CAPS KC_CAPSLOCK

// base layer aliases...
#define SCOL KC_SCLN                // ; :
#define COMM KC_COMM                // , >
#define DOT_ KC_DOT                 // . >
#define SLSH KC_SLSH                // / ?
#define QUOT KC_QUOTE

// symbol layer aliases...
#define HASH KC_HASH                // #
#define SQUO KC_QUOT                // '
#define PERC KC_PERC                // %
#define AMPR KC_AMPR                // &
#define LPRN KC_LPRN                // (
#define RPRN KC_RPRN                // )
#define PLUS KC_PLUS                // +
#define MINS KC_MINS                // -
#define EQUL KC_EQL                 // =
#define DQUO KC_DQUO                // "
#define AT__ KC_AT                  // @
#define PIPE KC_PIPE                // |
#define LBRC KC_LBRC                // [
#define RBRC KC_RBRC                // ]
#define ASTR KC_ASTR                // *
#define BTCK KC_GRV                 // `
#define DOLR KC_DLR                 // $
#define EXLM KC_EXLM                // !
#define LBRK KC_LCBR                // {
#define RBRK KC_RCBR                // }
#define CART KC_CIRC                // ^
#define TILD KC_TILD                // ~
#define BSLS KC_BSLS                // backslash
#define UNSC KC_UNDERSCORE          // _

// numeric layer aliases...
#define ALT1 LALT(KC_1)
#define ALT2 LALT(KC_2)
#define ALT3 LALT(KC_3)
#define ALT4 LALT(KC_4)
#define ALT5 LALT(KC_5)
#define ALT6 LALT(KC_6)
#define ALT7 LALT(KC_7)
#define ALT8 LALT(KC_8)
#define ALT9 LALT(KC_9)
#define ALT0 LALT(KC_0)

// function layer aliases...
#define F1__ KC_F1
#define F2__ KC_F2
#define F3__ KC_F3
#define F4__ KC_F4
#define F5__ KC_F5
#define F6__ KC_F6
#define F7__ KC_F7
#define F8__ KC_F8
#define F9__ KC_F9
#define F10_ KC_F10
#define F11_ KC_F11
#define F12_ KC_F12
#define HOME KC_HOME
#define PGDN KC_PGDN
#define PGUP KC_PGUP
#define END_ KC_END

// numpad layer aliases...
#define PSLS KC_PSLS
#define PAST KC_PAST
#define PMIN KC_PMNS
#define PPLS KC_PPLS
#define PENT KC_PENT
#define NP_1 KC_P1
#define NP_2 KC_P2
#define NP_3 KC_P3
#define NP_4 KC_P4
#define NP_5 KC_P5
#define NP_6 KC_P6
#define NP_7 KC_P7
#define NP_8 KC_P8
#define NP_9 KC_P9
#define NP_0 KC_P0
#define PDOT KC_PDOT

// misc. aliases...
#define NONE KC_NO
#define TRNS KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    _FNC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, BKSP,
    XCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SCOL, ENTR,
    SHFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, COMM, DOT_, SLSH, SHFT,
    DEL_, SUPR, CTRL, ALT_, _SYM, SPC_, SPC_, _NUM, LT__, DN__, UP__, RT__
),
/* ,-----------------------------------------------------------------------.
 * | tab |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | bsp |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | esc |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  | ; : | ent |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  v  |  b  |  n  |  m  | , < | . > | / ? | sft |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | del | win | ctl | alt | SYM |   space   | NUM | lft | dwn | up  | rgt |
 * `-----------------------------------------------------------------------`
 */


[_SYMBOLS] = LAYOUT_planck_grid(
    TRNS, NONE, NONE, SQUO, BSLS, PERC, AMPR, LBRC, RBRC, PLUS, MINS, EQUL,
    CAPS, NONE, NONE, NONE, DQUO, AT__, PIPE, LPRN, RPRN, ASTR, SQUO, DQUO,
    SHFT, NONE, NONE, NONE, BTCK, DOLR, EXLM, LBRK, RBRK, CART, TILD, SHFT,
    DEL_, SUPR, CTRL, ALT_, TRNS, UNSC, UNSC, HASH, NONE, NONE, NONE, NONE
),
/* ,-----------------------------------------------------------------------.
 * |  בּ  |     |     |  '  |  \  |  %  |  &  |  (  |  )  |  +  |  -  |  =  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | esc |     |     |     |  "  |  @  |  |  |  [  |  ]  |  *  |  '  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | sft |     |     |     |  `  |  $  |  !  |  {  |  }  |  ^  |  ~  | sft |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | del | win | ctl | alt | SYM |     _     |  #  |     |     |     |     |
 * `-----------------------------------------------------------------------`
 */


[_NUMERIC] = LAYOUT_planck_grid(
    DOLR, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, BKSP,
    XCTL, ALT1, ALT2, ALT3, ALT4, ALT5, ALT6, ALT7, ALT8, ALT9, ALT0, ENTR,
    SHFT, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, SHFT,
    DEL_, SUPR, CTRL, ALT_, NONE, SPC_, SPC_, TRNS, NONE, NONE, NONE, NONE
),
/* ,-----------------------------------------------------------------------.
 * |  $  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | bsp |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | esc |     |     |     |     |     |     |     |     |     |     | ent |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | sft |     |     |     |     |     |     |     |     |     |     | sft |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | del | win | ctl | alt |     |   space   | NUM |     |     |     |     |
 * `-----------------------------------------------------------------------`
 */


[_FUNC] = LAYOUT_planck_grid(
    TRNS, F1__, F2__, F3__, F4__, NONE, HOME, PGDN, PGUP, END_, NONE, BKSP,
    XCTL, F5__, F6__, F7__, F8__, NONE, LT__, DN__, UP__, RT__, NONE, ENTR,
    SHFT, F9__, F10_, F11_, F12_, NONE, NONE, NONE, NONE, NONE, NONE, SHFT,
    DEL_, SUPR, CTRL, ALT_, NONE, SPC_, SPC_, NONE, NONE, NONE, NONE, NONE
),
/* ,-----------------------------------------------------------------------.
 * | FNC | f_1 | f_2 | f_3 | f_4 |     | hme | pup | pdn | end |     | bsp |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | esc | f_5 | f_6 | f_7 | f_8 |     | lft | dwn | up  | rgt |     | ent |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | sft | f_9 | f10 | f11 | f12 |     |     |     |     |     |     | sft |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | del | win | ctl | alt | SYM |   space   |     |     |     |     |     |
 * `-----------------------------------------------------------------------`
 */



[_NUMPAD] = LAYOUT_planck_grid(
    TRNS, NONE, NONE, NONE, NONE, NONE, NONE, NP_7, NP_8, NP_9, PSLS, PAST,
    XCTL, NONE, NONE, NONE, NONE, NONE, NONE, NP_4, NP_5, NP_6, PMIN, PPLS,
    SHFT, NONE, NONE, NONE, NONE, NONE, NONE, NP_1, NP_2, NP_3, NONE, PENT,
    DEL_, SUPR, CTRL, ALT_, TRNS, SPC_, SPC_, NP_0, NP_0, PDOT, NONE, NONE
),
/* ,-----------------------------------------------------------------------.
 * | NPD |     |     |     |     |     |     |  7  |  8  |  9  |  /  |  *  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | esc |     |     |     |     |     |     |  4  |  5  |  6  |  -  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |  1  |  2  |  3  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | del | win | ctl | alt | SYM |   space   |  0  |  0  |  .  |     |     |
 * `-----------------------------------------------------------------------`
 */

};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SYMBOLS, _FUNC, _NUMPAD);
}



#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)
#define PERMISSIVE_HOLD

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  EPRM,
  ARROW_FN,
  JS_CONST,
  FWD_PIPE,
  LAMBDA,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
  _ACCENT,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum unicode_names {
    LOWER_ARING,
    LOWER_ADIER,
    LOWER_ODIER,
    UPPER_ARING,
    UPPER_ADIER,
    UPPER_ODIER,
    LOWER_AACUTE,
    UPPER_AACUTE,
    LOWER_CCEDIL,
    UPPER_CCEDIL,
    LOWER_AGRAVE,
    UPPER_AGRAVE,
    LOWER_ACIRC,
    UPPER_ACIRC,
    LOWER_ATILDE,
    UPPER_ATILDE,
    LOWER_EACUTE,
    UPPER_EACUTE,
    LOWER_ECIRC,
    UPPER_ECIRC,
    LOWER_IACUTE,
    UPPER_IACUTE,
    LOWER_OACUTE,
    UPPER_OACUTE,
    LOWER_OCIRC,
    UPPER_OCIRC,
    LOWER_OTILDE,
    UPPER_OTILDE,
    LOWER_UACUTE,
    UPPER_UACUTE,
};

const uint32_t PROGMEM unicode_map[] = {
    [LOWER_ARING] = 0x00E5,
    [LOWER_ADIER] = 0x00E4,
    [LOWER_ODIER] = 0x00F6,
    [UPPER_ARING] = 0x00C5,
    [UPPER_ADIER] = 0x00C4,
    [UPPER_ODIER] = 0x00D6,
    [LOWER_AACUTE] = 0x00E1,
    [UPPER_AACUTE] = 0x00C1,
    [LOWER_CCEDIL] = 0x00E7,
    [UPPER_CCEDIL] = 0x00C7,
    [LOWER_AGRAVE] = 0x00E0,
    [UPPER_AGRAVE] = 0x00C0,
    [LOWER_ACIRC] = 0x00E2,
    [UPPER_ACIRC] = 0x00C2,
    [LOWER_ATILDE] = 0x00E3,
    [UPPER_ATILDE] = 0x00C3,
    [LOWER_EACUTE] = 0x00E9,
    [UPPER_EACUTE] = 0x00C9,
    [LOWER_ECIRC] = 0x00EA,
    [UPPER_ECIRC] = 0x00CA,
    [LOWER_IACUTE] = 0x00ED,
    [UPPER_IACUTE] = 0x00CD,
    [LOWER_OACUTE] = 0x00F3,
    [UPPER_OACUTE] = 0x00D3,
    [LOWER_OCIRC] = 0x00F4,
    [UPPER_OCIRC] = 0x00D4,
    [LOWER_OTILDE] = 0x00F5,
    [UPPER_OTILDE] = 0x00D5,
    [LOWER_UACUTE] = 0x00FA,
    [UPPER_UACUTE] = 0x00DA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPC,
    KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_ENTER,
    LSFT_T(KC_MINUS),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,RSFT_T(KC_QUOTE),
    KC_LCTL,MT(MOD_HYPR, KC_DELETE),MT(MOD_LALT,KC_INS),KC_LGUI,LOWER,LT(_FN, KC_SPACE),KC_NO,RAISE,LT(_ACCENT, KC_RGUI),MT(MOD_LALT,KC_INS),MT(MOD_HYPR, KC_DELETE),KC_RCTL),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT,FWD_PIPE,JS_CONST,ARROW_FN,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_BSLS,KC_EQL,KC_LBRC,KC_RBRC,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TRANSPARENT,
    KC_TRANSPARENT,LAMBDA,KC_TRANSPARENT,KC_TRANSPARENT,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_PIPE,KC_PLUS,KC_LCBR,KC_RCBR,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
    ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_F12,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_F11,UP(LOWER_ARING,UPPER_ARING),UP(LOWER_ADIER,UPPER_ADIER),UP(LOWER_ODIER,UPPER_ODIER),UP(LOWER_AACUTE,UPPER_AACUTE),UP(LOWER_CCEDIL,UPPER_CCEDIL),KC_CAPS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
    ),

  [_ADJUST] = LAYOUT_planck_grid(
    UC_NEXT,UC_WINC,UC_MAC,UC_LINX,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_DELETE,KC_TRANSPARENT,AU_ON,AU_OFF,AU_TOGG,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,QK_BOOT,
    KC_TRANSPARENT,KC_TRANSPARENT,MU_OFF,MU_OFF,MU_TOGG,MU_NEXT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MPRV,KC_MNXT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY
    ),

  [_FN] = LAYOUT_planck_grid(
    KC_TRANSPARENT,KC_WWW_BACK,KC_HOME,KC_UP,KC_END,KC_WWW_FORWARD,KC_KP_SLASH,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_MINUS,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_WWW_REFRESH,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_KP_ASTERISK,KC_KP_4,KC_5,KC_KP_6,KC_KP_PLUS,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_PGDN,KC_TRANSPARENT,KC_PGUP,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_DOT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_KP_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
    ),

  [_ACCENT] = LAYOUT_planck_grid(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,UP(LOWER_EACUTE,UPPER_EACUTE),UP(LOWER_ECIRC,UPPER_ECIRC),KC_TRANSPARENT,KC_TRANSPARENT,UP(LOWER_UACUTE,UPPER_UACUTE),UP(LOWER_IACUTE,UPPER_IACUTE),UP(LOWER_OACUTE,UPPER_OACUTE),UP(LOWER_OCIRC,UPPER_OCIRC),KC_TRANSPARENT,
    KC_TRANSPARENT,UP(LOWER_AACUTE,UPPER_AACUTE),UP(LOWER_ACIRC,UPPER_ACIRC),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,UP(LOWER_OTILDE,UPPER_OTILDE),KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,UP(LOWER_ATILDE,UPPER_ATILDE),UP(LOWER_AGRAVE,UPPER_AGRAVE),UP(LOWER_CCEDIL,UPPER_CCEDIL),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case EPRM:
        if (record->event.pressed) {
          eeconfig_init();
        }
        return false;
      case RGB_SLD:
          return false;
      case ARROW_FN:
        if  (record->event.pressed) {
          SEND_STRING("=> ");
        }
        break;
      case JS_CONST:
        if (record->event.pressed) {
          SEND_STRING("const ");
        }
        break;
      case FWD_PIPE:
        if (record->event.pressed) {
          SEND_STRING("|> ");
        }
        break;
      case LAMBDA:
        if (record->event.pressed) {
          SEND_STRING("-> ");
        }
        break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
    return false;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

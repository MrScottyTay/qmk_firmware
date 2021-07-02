/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _QWERTY,
  // _COLEMAK,
  _GAMING,
  _LOWER,
  _LOWER_GAMING,
  _RAISE,
  _RAISE_GAMING,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  // COLEMAK,
  BACKLIT,
  GAMING
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
// #define GAMING DF(_GAMING)
#define LOW_GM MO(_LOWER_GAMING)
#define RSE_GM MO(_RAISE_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |Enter |   H  |   J  |   K  |   L  |  ;:  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \|  |   Z  |   X  |   C  |   V  |   B  |  '@  |   N  |   M  |  ,<  |  .>  |  /?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | GUI  | Ctrl | Shift|Lower |    Space    |Raise |RShift| RCtrl| RGui | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
    KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 
    KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RSFT, KC_RCTL, KC_RGUI, KC_LALT
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \|  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Shift|Lower |    Space    |Raise |RShift| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, LOW_GM,  KC_SPC,  KC_SPC,  RSE_GM, KC_RSFT, KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
// [_COLEMAK] = LAYOUT_planck_grid(
//     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
//     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
*  |   ¬  |   £  |   &  |   +  |   {  |   }  |      |   #  |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   !  |   "  |   -  |   (  |   )  |      |   =  |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   $  |   ~  |   *  |   [  |   ]  |      |   _  |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_HASH, KC_AMPR,    KC_PLUS, KC_LCBR, KC_RCBR, _______, KC_HASH, KC_7, KC_8,   KC_9,    _______,
    KC_GRV,  KC_EXLM, KC_AT,      KC_MINS, KC_LPRN, KC_RPRN, _______, KC_EQLS, KC_4, KC_5,   KC_6,    _______,
    KC_CIRC, KC_DLR,  S(KC_NUHS), KC_ASTR, KC_LBRC, KC_RBRC, _______, KC_UNDS, KC_1, KC_2,   KC_3,    _______,
    _______, _______, _______,    _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______
),

/* Lower Gaming
 * ,-----------------------------------------------------------------------------------.
*  |      |   1  |   2  |   3  |   -  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   =  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |   0  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER_GAMING] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_MINS, _______, _______, _______, _______, _______, _______, QWERTY,
    _______, KC_4,    KC_5,    KC_6,    KC_EQL,  _______, _______, _______, _______, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |W Back| W Fwd|Ms Up | XXXX | XXXX |      | XXXX | Home |  Up  |  End |Pg Up |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MsSpd1|Ms Lft|Ms Dwn|MsRght|MsW Up|      | MsB1 | Left | Down | Right|Pg Dwn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MsSpd2|MsSpd0| XXXX |MsWLft|MsWRgt|MsWDwn|      | MsB2 | MsB3 | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_WBAK, KC_WFWD, KC_MS_U, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, KC_BTN1, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_ACL2, KC_ACL0, XXXXXXX, KC_WH_L, KC_WH_R, KC_WH_D, _______, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise Gaming
 * ,-----------------------------------------------------------------------------------.
*  |      |   1  |   2  |   3  |   -  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   =  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |   0  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE_GAMING] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, QWERTY,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |  F1  |  F2  |  F3  |  F4  |AudTog|MIDTog| XXXX | VOL- | VOL+ | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Debug |  F5  |  F6  |  F7  |  F8  |MusTog|MusMod| XXXX | Play | Prev | Next | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BRITE |  F9  |  F10 |  F11 |  F12 |Voice-|Voice+| XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   AU_TOG,  MI_TOG,  XXXXXXX, KC_VOLD, KC_VOLU,  XXXXXXX, GAMING,
    DEBUG,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   MU_TOG,  MU_MOD,  XXXXXXX, KC_MPLY, KC_MPRV,  KC_MNXT, XXXXXXX,
    BACKLIT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  MUV_DE,  MUV_IN,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


// qk_tap_dance_action_t tap_dance_actions[] = {
//   //tap once for CTRL tap twice for gui
//   [TD_CTL_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_LGUI)
// }


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

float gaming_song[][2] = SONG(DVORAK_SOUND);

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        layer_off(_GAMING);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        print("mode just switched to gaming\n");
        layer_on(_GAMING);
        PLAY_SONG(gaming_song);
      }
      return false;
      break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    case BACKLIT:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
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
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {  }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {  }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
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

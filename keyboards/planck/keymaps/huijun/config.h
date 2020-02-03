#pragma once

#ifdef AUDIO_ENABLE
    #include "removed_songs.h"
    #define STARTUP_SONG SONG(_FF_PRELUDE)
    // #define STARTUP_SONG SONG(NO_SOUND)
    // #define GOODBYE_SONG SONG(NO_SOUND) // plays when you press the RESET key (quantum.c)
    // #define AG_NORM_SONG SONG(NO_SOUND) // plays when you press AG_NORM (quantum.c)
    // #define AG_SWAP_SONG SONG(NO_SOUND) // plays when you press AG_SWAP (quantum.c)
    // #define CG_NORM_SONG SONG(NO_SOUND) // plays when you press CG_NORM (quantum.c)
    // #define CG_SWAP_SONG SONG(NO_SOUND) // plays when you press CG_SWAP (quantum.c)
    // #define MUSIC_ON_SONG SONG(NO_SOUND) // plays when music mode is activated (process_music.c)
    // #define MUSIC_OFF_SONG SONG(NO_SOUND) // plays when music mode is deactivated (process_music.c)
    // #define CHROMATIC_SONG SONG(NO_SOUND) // plays when the chromatic music mode is selected (process_music.c)
    // #define GUITAR_SONG SONG(NO_SOUND) // plays when the guitar music mode is selected (process_music.c)
    // #define VIOLIN_SONG SONG(NO_SOUND) // plays when the violin music mode is selected (process_music.c)
    // #define MAJOR_SONG SONG(NO_SOUND) // plays when the major music mode is selected (process_music.c)
    #define DEFAULT_LAYER_SONGS { SONG(_ZELDA_PUZZLE), \
                                  SONG(_ONE_UP_SOUND), \
                                  SONG(_ZELDA_TREASURE) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 440.0f
#define AUDIO_CLICKY_FREQ_MIN 65.0f
#define AUDIO_CLICKY_FREQ_MAX 1500.0f
#define AUDIO_CLICKY_FREQ_FACTOR 1.18921f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
#define AUDIO_CLICKY_DELAY_DURATION 6

#define NO_DEBUG
#define NO_PRINT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define UNICODE_SELECTED_MODES UC_OSX, UC_LNX, UC_WINC

#define UNICODE_SONG_OSX SONG(SCROLL_LOCK_ON_SOUND)
#define UNICODE_SONG_LNX SONG(UNICODE_LINUX)
#define UNICODE_SONG_WINC SONG(UNICODE_WINDOWS)

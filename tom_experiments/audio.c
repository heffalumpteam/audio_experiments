#include <stdio.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"

#define SAMPLERATE 44100
#define NUMAUDIOCHANNELS 2
#define BUFFSIZE 2048

Mix_Chunk *drum1_sound = NULL;

void audio_init(void){
  /*                 FS, sample format, num channels, sample size 2kb*/
  if( Mix_OpenAudio( SAMPLERATE, MIX_DEFAULT_FORMAT, NUMAUDIOCHANNELS, BUFFSIZE ) < 0 ){
    printf( "SDL_mixer Error: %s\n", Mix_GetError() );
  }
  drum1_sound = Mix_LoadWAV("../WAVs/FatkickVES2023.wav");
  if(drum1_sound == NULL){
    printf("Drums failed %s\n", Mix_GetError());
  }
}

void audio_close(void){
  Mix_FreeChunk(drum1_sound);

  drum1_sound = NULL;

  Mix_Quit();
}

void audio_play(enum audiofiles sound){
  switch (sound) {
    case drum1:
      Mix_PlayChannel( -1, drum1_sound, 0 ); /* (channel -1 = dont care, sound, times to repeat)*/
      break;
    default:
      break;
  }
}

#include "events.h"
#include "graphics.h"
#include "audio.h"

void drum1(void){
  audio_play();
}

void quitting(void){
  audio_close();
  graphics_close();
}

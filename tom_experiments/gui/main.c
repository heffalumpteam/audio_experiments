#include "graphics.h"
#include "audio.h"

unsigned char running = 1;

int main (){

  audio_init();
  graphics_init();
  while(running){

  }
  return 0;
}

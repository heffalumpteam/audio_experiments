/*gcc main.c -o test -Wall -Wextra -pedantic -std=c90 -lSDL2*/
#include <stdio.h>
#include <SDL2/SDL_timer.h>
#include "def.h"
#include "graphics.h"
#include "events.h"
#include "audio.h"

void graphics_init(void);

int main (){
  byte running = 1;
  byte beat = 1;
  unsigned int bar = 0;
  unsigned int new_tick = 0;
  unsigned int old_tick = 0;

  graphics_init();
  audio_init();

  while(running){ /*program happens in this loop*/
    events_poll(&running);
    new_tick = SDL_GetTicks();
    if(new_tick != old_tick){
      /*new ms!*/
      if(new_tick % MS_PER_BAR == 0){
        bar++;
        printf("Bar: %d\n", bar);
      }
      if(new_tick % MS_PER_BEAT == 0){
        beat++;
        if(beat > 4){
          beat = 1;
        }
        printf("%d\n", beat);
        audio_play(drum1);
      }
      old_tick = new_tick;
    }
  }

  audio_close();
  graphics_close();
  return 0;
}

#include <SDL2/SDL.h>
#include "def.h"

enum eventreturns {noaction, quit, drums};

enum eventreturns checkEvents(void);
enum eventreturns keydown(SDL_Event event);

void events_poll(byte *running){

  switch (checkEvents()){
    case noaction:
      break;
    case quit:
      *running = 0;
      break;
    case drums:
      /*audio_play(drums);*/
      break;
    default:
      printf("Unknown event\n");
      break;
    }
}

enum eventreturns checkEvents(void){
  SDL_Event event;
  enum eventreturns to_return = noaction;

  if (SDL_PollEvent(&event)){
    switch (event.type){
      case SDL_QUIT:
        to_return = quit;
        break;
      case SDL_KEYDOWN:
        to_return = keydown(event);
        break;
    }
  }

  return to_return;
}

enum eventreturns keydown(SDL_Event event){
  enum eventreturns to_return = noaction;

  switch (event.key.keysym.sym){
    case SDLK_ESCAPE:
      to_return = quit;
      break;
    case SDLK_a:
      to_return = drums;
      break;
    default:
      to_return = noaction;
      break;
  }
  return to_return;
}

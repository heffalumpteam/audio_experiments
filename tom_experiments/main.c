/*gcc main.c -o test -Wall -Wextra -pedantic -std=c90 -lSDL2*/
#include <stdio.h>
#include "def.h"
#include "graphics.h"
#include "events.h"


void graphics_init(void);

int main (){
  byte running = 1;

  graphics_init();

  while(running){ /*program happens in this loop*/
    events_poll(&running);
  }

  graphics_close();
  return 0;
}

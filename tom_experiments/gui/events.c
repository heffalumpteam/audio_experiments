#include <gtk/gtk.h>
#include <glib.h>

#include "events.h"
#include "graphics.h"
#include "audio.h"

gboolean events_mainLoop(gpointer user_data){
  /*https://developer.gnome.org/gtk-tutorial/stable/c1759.html*/
  /*This loop runs every NUM_MS and takes the place of code that would usually be in main()*/

  return 1; /*Must return 1 if we want the loop to be called again*/
}

void drum1(void){
  audio_play();
}

void quitting(void){
  audio_close();
  graphics_close();
}

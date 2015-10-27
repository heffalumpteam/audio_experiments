#include <gtk/gtk.h>
#include <glib.h>

#include "graphics.h"
#include "events.h"
#include "audio.h"

extern unsigned char running;

void attachFunctions(GtkBuilder *builder);

void graphics_init(void){
  GtkBuilder *builder;

  gtk_init (NULL, NULL);

  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "ui.ui", NULL);

  attachFunctions(builder);

  g_object_unref( G_OBJECT( builder ) );
  gtk_main ();
}

void attachFunctions(GtkBuilder *builder){
  GObject *window;
  GObject *button;
  guint timeoutID;

  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (quitting), NULL);

  timeoutID = g_timeout_add(NUM_MS, events_mainLoop, NULL);

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (drum1), NULL);
}

void graphics_close(void){
  gtk_main_quit();
}

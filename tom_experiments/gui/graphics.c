#include "graphics.h"
#include "audio.h"

extern unsigned char running;

static void drum1(void);
void attachFunctions(GtkBuilder *builder);
void quit_button(void);

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

  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (quit_button), NULL);

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (drum1), NULL);
}

static void drum1(void){
  g_print ("drum1\n");
  audio_play();
}

void quit_button(void){
  running = 0;
  audio_close();
  gtk_main_quit();
}

void graphics_close(void){
  gtk_main_quit();
}

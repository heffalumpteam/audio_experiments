Make using the following commands:

For Linux:
  make linux  <- This works on my install of Ubuntu.
                 If it doesn't work for you please
                 add another entry in to the make file
                 rather than changing this one.

For MacOS:
  make mac <- I doubt this will work. Please change it to make it work.
              There are also ifdefs in audio.c that will need to be corrected.
              We may need to add an ifdef to graphics.c for the gtk library.
              Feel free!

For Windows:
  make win <- As above. I doubt this will work. Please change it to make it work.
              There are also ifdefs in audio.c feel free to ad the windows version
              on to the end. We may need to add an ifdef to graphics.c for the gtk
              library. Feel free!

To run the program "make run" should work!

NAME = test

CFILES = main.c graphics.c audio.c

CFLAGS = -Wall -Wextra -pedantic -std=c90

LIBS = -lm -lSDL2 -lSDL2_mixer

GTK = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

OFLAGS = -O3


$(NAME) : $(CFILES)
	gcc $(CFILES) -o $(NAME) $(CFLAGS) $(GTK) $(LIBS)

run: $(NAME)
	./$(NAME)

clean:
	rm $(NAME)

optimised: $(CFILES)
	gcc $(CFILES) -o $(NAME) $(OFLAGS) $(CFLAGS) $(LIBS)

windows32:
	i686-w64-mingw32-gcc $(CFILES) -o $(NAME)_win32.exe $(CFLAGS) $(LIBS)

windows64:
	x86_64-w64-mingw32-gcc $(CFILES) -o $(NAME)_win64.exe $(CFLAGS) $(LIBS)

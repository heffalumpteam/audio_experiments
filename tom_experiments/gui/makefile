NAME = test

CFILES = main.c graphics.c audio.c events.c

CFLAGS = -Wall -Wextra -Wfloat-equal -pedantic -std=c90

OFLAGS = -O3

linuxLIBS = -lm -lSDL2 -lSDL2_mixer
macLIBS = -lm -lSDL2 -lSDL2_mixer
linLIBS = -lm -lSDL2 -lSDL2_mixer

linuxGTK = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
macGTK = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
winGTK = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`



$(NAME) :

linux : $(CFILES)
	gcc $(CFILES) -o $(NAME) $(CFLAGS) $(linuxGTK) $(linuxLIBS)

mac : $(CFILES)
	gcc $(CFILES) -o $(NAME) $(CFLAGS) $(macGTK) $(macLIBS)

run: $(NAME)
	./$(NAME)

clean:
	rm $(NAME)

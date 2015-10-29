PROGRAMNAME = audio

CFLAGS = -Wall -Wextra -pedantic -std=c99

linuxLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer
macLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer

CFILES = SDLaudiointro.c

prog :


linux : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(linuxLIBS)

mac : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(macLIBS)

run: $(PROGRAMNAME)
	./$(PROGRAMNAME)

clean:
	rm $(PROGRAMNAME)

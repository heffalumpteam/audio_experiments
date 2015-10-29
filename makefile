PROGRAMNAME = audio

CFLAGS = -Wall -Wextra -pedantic -std=c99

linuxLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer

INCLUDES = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers
FRAMEWORKS = -F/Library/Frameworks -framework SDL2 -framework SDL2_mixer

CFILES = SDLaudiointro.c

prog :


linux : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(linuxLIBS)

mac : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(FRAMEWORKS) $(INCLUDES)

run: $(PROGRAMNAME)
	./$(PROGRAMNAME)

clean:
	rm $(PROGRAMNAME)

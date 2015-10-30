PROGRAMNAME = prog

CFLAGS = -Wall -Wextra -pedantic -std=c90

linuxLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer

macLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer
macINCLUDES = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers
macFRAMEWORKS = -F/Library/Frameworks -framework SDL2 -framework SDL2_mixer

winINCLUDES = -lm -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lmingw32 -mwindows

CFILES = main.c graphics.c events.c audio.c

prog :


linux : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(linuxLIBS)

mac : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(macLIBS)

windows :
	gcc -std=c99 -O3 -Wall -pedantic -o $(PROGRAMNAME).exe $(CFILES) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

run: $(PROGRAMNAME)
	./$(PROGRAMNAME)

clean:
	rm $(PROGRAMNAME)

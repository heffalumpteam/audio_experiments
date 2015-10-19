PROGRAMNAME = prog

CFLAGS = -Wall -Wextra -pedantic -std=c90

linuxLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer
macLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer

CFILES = main.c graphics.c events.c audio.c

prog : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(LIBS)

linux : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(linuxLIBS)

mac : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(LIBS)

run: $(PROGRAMNAME)
	./$(PROGRAMNAME)

clean:
	rm $(PROGRAMNAME)

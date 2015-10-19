PROGRAMNAME = prog

CFLAGS = -Wall -Wextra -pedantic -std=c90

LIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer

CFILES = main.c graphics.c events.c audio.c

prog : $(CFILES)
	gcc $(CFILES) -o $(PROGRAMNAME) $(CFLAGS) $(LIBS)

run: $(PROGRAMNAME)
	./$(PROGRAMNAME)

clean:
	rm $(PROGRAMNAME)

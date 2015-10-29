#include <SDL2/SDL.h>
#ifdef __APPLE__
	#include <SDL2_mixer/SDL_mixer.h>
#elif __LINUX__
	#include <SDL2/SDL_mixer.h>
#elif _WIN32
  #include <SDL2/SDL_mixer.h>
#elif _WIN64
  #include <SDL2/SDL_mixer.h>
#endif
#include <stdio.h>
#include <stdbool.h>

void graphics_init(void);
void loadMedia(Mix_Chunk** sample, Mix_Chunk** sample2);
void audio_init(void);
Uint32 callbackfunc(Uint32 interval, void* param);

int main(int argc, char *argv[])
{
	Mix_Chunk* sample = NULL;
	Mix_Chunk* sample2 = NULL;
	_Bool quit = false; /* Global quit flag */
	SDL_Event event;
	SDL_TimerID timer;

	printf("a is BD and f is clap\n");

	/* Initialize SDL, then create a window, then initialize audio. Finally, load
		the WAV file into the program from disk */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		printf("Could not initialize SDL! Error: %s\n", SDL_GetError());
	}
	graphics_init();
	audio_init();
	loadMedia(&sample, &sample2);


	/* Main loop */
	while (!quit)
	{
		/* Process the event queue while there are events to be processed */
		while (SDL_PollEvent(&event) != 0)
		{
			/* If user selects to quit (by clicking X to close the window), set quit to true
				which will then exit the main loop and quit the program */
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			/* If a key press is detected */
			if (event.type == SDL_KEYDOWN)
			{
				/* And it's the 'A' key (denoted by SDLK_a), then create a new timer
					that calls 'callbackfunc' every 500ms */
				if (event.key.keysym.sym == SDLK_a)
				{
					timer = SDL_AddTimer(500, callbackfunc, sample);
				}
				/* Same thing for the 'F' key, but the sample passed in is different */
				if (event.key.keysym.sym == SDLK_f)
				{
					SDL_TimerID timer2 = SDL_AddTimer(500, callbackfunc, sample2);
				}
			}
		}



	}
	return 0;
}

/* Tom's function, same as in the SDL Intro file */
void graphics_init(void)
{
	SDL_Window *window = NULL;

	window = SDL_CreateWindow("Testing",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		0);

	// SDL_Delay(2000);
	// SDL_DestroyWindow(window);
	// window = NULL;
	// SDL_Quit();
}

/* Initialize SDL_Mixer. See parameters to Mix_OpenAudio from SDL_Mixer reference */
void audio_init(void)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("Could not initialize audio! Error: %s\n", Mix_GetError());
	}
}

/* Loads the two samples into memory, each sample returns error if it fails to load */
void loadMedia(Mix_Chunk** sample, Mix_Chunk** sample2)
{
	*sample = Mix_LoadWAV("WAVs/FatkickVES2023.wav");
	if (*sample == NULL)
	{
		printf("Failed to load sample! Error: %s\n", Mix_GetError());
	}

	*sample2 = Mix_LoadWAV("WAVs/MUB1Clap004.wav");
	if (*sample2 == NULL)
	{
		printf("Failed to load sample! Error: %s\n", Mix_GetError());
	}
}

/* The function that the timer will call every x milliseconds. This just plays the sample once */
Uint32 callbackfunc(Uint32 interval, void* param)
{
	Mix_PlayChannel(-1, (Mix_Chunk*)param, 0);
	return interval;

}

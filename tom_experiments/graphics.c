#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Surface *image = NULL;
SDL_Texture *texture = NULL;

void graphics_init(void){
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  window = SDL_CreateWindow("Testing",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            800,
                            600,
                            SDL_WINDOW_ALLOW_HIGHDPI);

  renderer = SDL_CreateRenderer(window, -1, 0);

  image = IMG_Load("ourimage.png");
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  image = NULL;


  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, 0, 0);
  SDL_RenderPresent(renderer);
}

void graphics_close(void){
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}
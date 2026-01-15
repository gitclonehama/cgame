#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL_Init Error: %s", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("SDL3 Nob Window", 800, 600, 0);
  if (!window) {
    SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  for (int i = 0; i < argc; ++i) {
    printf("ARGC: %d\n", argc);
    printf("ARG[%d]: %s\n", i, argv[i]);
  }

  bool quit = false;
  SDL_Event event;

  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        quit = true;
      }
    }

    SDL_SetRenderDrawColor(renderer, 24, 69, 59, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

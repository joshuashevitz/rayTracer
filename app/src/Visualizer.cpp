#include "app/Visualizer.h"

#include <stdexcept>
#include <algorithm>

using namespace Renderer;

Renderer::Display::Display(const int ResX, const int ResY){
  if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0){
    throw std::runtime_error(SDL_GetError());
  }

  window = SDL_CreateWindow("RayTracer Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ResX, ResY, SDL_WINDOW_SHOWN);
  if(window == NULL){
    throw std::runtime_error(SDL_GetError());
  }

  // Grab the current windows surface.
  surface = SDL_GetWindowSurface(window);
}

Renderer::Display::~Display(){
  if(window != nullptr){
    SDL_DestroyWindow(window);
  }

  SDL_Quit();
}

void Display::Update(){
  SDL_Event e;
  while(SDL_PollEvent(&e)){
    if(e.type == SDL_QUIT){
      running = false;
    }
  }
}

void Display::DrawCanvas(const canvas &c){
  unsigned int *pixels = (unsigned int*)surface->pixels;

  for(std::size_t x = 0; x < c.width; x++){
    for(std::size_t y = 0; y < c.height; y++){
      const color col = c.pixelMap[x][y];

      uint8_t r = (255 * col.red);
      uint8_t g = (255 * col.green);
      uint8_t b = (255 * col.blue);


      Uint32 pixel = SDL_MapRGB(surface->format, r, g, b);

      pixels[x + y * surface->w] = pixel;
    }
  }

  SDL_UpdateWindowSurface(window);
}

bool Renderer::Display::IsRunning(){
  return running;
}

#pragma once

#include <SDL3/SDL.h>
#include <objects/Canvas.h>

namespace Renderer{
  class Display{
  public:
    Display(const int ResX, const int ResY);
    ~Display();

    void Update();
    void DrawCanvas(const canvas &c);

    bool IsRunning();

  private:
    SDL_Window *window;
    SDL_Surface *surface;

    bool running = true;
  };
}
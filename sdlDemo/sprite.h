#ifndef SPRITE_H_EXISTS
#define SPRITE_H_EXISTS

#include <SDL2/SDL.h>

class Sprite {
  private:
    SDL_Renderer* ren;
    SDL_Rect rect;
    SDL_Color color;
    int x, y;
    int width, height;

  public:
    Sprite(SDL_Renderer* ren);
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setColor(int r, int g, int b, int a);
    void mainLoop();
    void process();
};

#endif

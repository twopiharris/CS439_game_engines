#ifndef SPRITE_H_EXISTS
#define SPRITE_H_EXISTS

#include <SDL2/SDL.h>
#include "scene.h"

class Sprite {
  private:
    SDL_Renderer* ren;
    SDL_Rect rect;
    SDL_Color color;
    int x, y;
    int width, height;
    Scene* scene;

  public:
    Sprite(Scene* scene);
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setColor(int r, int g, int b, int a);
    void mainLoop();    void process();
    bool isKeyPressed(SDL_Scancode);
    void checkBounds();
};
#endif

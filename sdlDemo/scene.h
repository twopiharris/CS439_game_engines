#include <SDL2/SDL.h>
#include <vector>
#include "sprite.h"

#ifndef SCENE_H_EXISTS
#define SCENE_H_EXISTS

class Scene {
  protected:
    int width;
    int height;
    SDL_Renderer* ren;

    //std::vector<Sprite*> spriteList;

  public:
    Scene();
    bool start();
    void mainLoop();
    void process();
    bool isKeyPressed(SDL_Scancode key);
    SDL_Renderer* getRen();
    int getWidth();
    int getHeight();
}; // end class def

#endif



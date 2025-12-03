#include <SDL2/SDL.h>
#include "sprite.h"

#ifndef SCENE_H_EXISTS
#define SCENE_H_EXISTS

class Scene {
  public:
    Scene();
    bool start();
    void mainLoop(SDL_Renderer* ren);
}; // end class def

#endif



// basic scene class
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include "scene.h"
#include "sprite.h"

#define WINDOW_W 800
#define WINDOW_H 600
#define SQUARE_SIZE 48

    Scene::Scene(){
      this->width = WINDOW_W;
      this->height = WINDOW_H;
      //this->start();
    } // end constructor

    bool Scene::start() {
      bool error = false;
      if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        error = true;
      } // end if

      SDL_Window *win = SDL_CreateWindow("SDL2 Basic Game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_W, WINDOW_H,
                                       SDL_WINDOW_SHOWN);
      if (!win) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        error = true;
      } // end if

      this->ren = SDL_CreateRenderer(win, -1, 
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (!this->ren) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        error = true;
      }

      if (error == false){
        this->mainLoop();
      } // end if

    // clean everything up
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return error;

  } // end start

  void Scene::mainLoop(){
    
    const int speed = 300; // pixels per second

    bool keepGoing = true;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta = 0;

    Sprite sprite(this);
    
    int currentX = 100;
    int currentY = 100;

    while (keepGoing) {
        last = now;
        now = SDL_GetPerformanceCounter();
        delta = (double)((now - last) * 1000) / (double)SDL_GetPerformanceFrequency(); // ms
        double seconds = delta / 1000.0;

        SDL_Event e;
        // put event-handling code here
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT){
              keepGoing = false;
            } // end if
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE){ 
                  keepGoing = false;
                } // end if
            } // end if
        } // end while

        // render
        SDL_SetRenderDrawColor(this->ren, 30, 30, 40, 255);
        SDL_RenderClear(this->ren);

        sprite.mainLoop();
        this->process();


        SDL_RenderPresent(this->ren);

        // small delay to avoid 100% CPU in case vsync is off
        SDL_Delay(1);
    }

  } // end mainLoop

  void Scene::process(){
    // generally an abstract function

  } // end process

  bool Scene::isKeyPressed(SDL_Scancode key){
    bool result = false; 
    //SDL_PumpEvents();
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[key]){
      result = true;
    } // end if
    return result;

  } // end isKeyPressed

  SDL_Renderer* Scene::getRen(){
    return this->ren;
  }  // end getRen

  int Scene::getWidth(){
	  return this->width;
  } // end getWidth
    
  int Scene::getHeight(){
    return this->height;
  } // end getHeight

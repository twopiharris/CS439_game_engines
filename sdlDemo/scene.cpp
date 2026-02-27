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
      this->start();
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

      SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (!ren) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        error = true;
      }

      if (error == false){
        this->mainLoop(ren);
      } // end if

    // clean everything up
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return error;

  } // end start

  void Scene::mainLoop(SDL_Renderer* ren){
    SDL_Rect player = { WINDOW_W/2 - SQUARE_SIZE/2, WINDOW_H/2 - SQUARE_SIZE/2, SQUARE_SIZE, SQUARE_SIZE };
    const int speed = 300; // pixels per second

    bool keepGoing = true;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta = 0;

    Sprite sprite(ren);
    
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

/*
        player.x += (int)(dx * speed * seconds);
        player.y += (int)(dy * speed * seconds);

        // clamp to window
        if (player.x < 0) player.x = 0;
        if (player.y < 0) player.y = 0;
        if (player.x + player.w > WINDOW_W) player.x = WINDOW_W - player.w;
        if (player.y + player.h > WINDOW_H) player.y = WINDOW_H - player.h;
*/

        // render
        SDL_SetRenderDrawColor(ren, 30, 30, 40, 255);
        SDL_RenderClear(ren);

        // draw player
        //SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
        //SDL_RenderFillRect(ren, &player);

        if (this->isKeyPressed(SDL_SCANCODE_A)){
          currentX -= 2;
	}
	if (this->isKeyPressed(SDL_SCANCODE_D)){
	  currentX += 2;
        }
        if (this->isKeyPressed(SDL_SCANCODE_W)){
          currentY -= 2;
	}
        if (this->isKeyPressed(SDL_SCANCODE_S)){
          currentY += 2;
	}
        sprite.setPosition(currentX, currentY);


        sprite.mainLoop();

        //SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
        //SDL_Rect border = {10, 10, WINDOW_W - 20, WINDOW_H - 20};
        //SDL_RenderDrawRect(ren, &border);

        SDL_RenderPresent(ren);

        // small delay to avoid 100% CPU in case vsync is off
        SDL_Delay(1);
    }

  } // end mainLoop

  bool Scene::isKeyPressed(SDL_Scancode key){
    //std::cout << "I got to isKeyPressed: " << key << std::endl;
    bool result = false; 
    SDL_PumpEvents();
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[key]){
      result = true;
    } // end if
    return result;

  } // end isKeyPressed



// basic scene class
#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define SQUARE_SIZE 48

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


class Scene {

  public:
    Scene(){
      this->start();
    } // end constructor

    bool start() {
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

  } // end init

  void mainLoop(SDL_Renderer* ren){
    SDL_Rect player = { WINDOW_W/2 - SQUARE_SIZE/2, WINDOW_H/2 - SQUARE_SIZE/2, SQUARE_SIZE, SQUARE_SIZE };
    const int speed = 300; // pixels per second

    bool keepGoing = true;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta = 0;

    Sprite sprite(ren);

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


        const Uint8 *ks = SDL_GetKeyboardState(NULL);
        // keyboard handler here?
        int dx = 0, dy = 0;
        if (ks[SDL_SCANCODE_LEFT] || ks[SDL_SCANCODE_A]) dx = -1;
        if (ks[SDL_SCANCODE_RIGHT] || ks[SDL_SCANCODE_D]) dx = 1;
        if (ks[SDL_SCANCODE_UP] || ks[SDL_SCANCODE_W]) dy = -1;
        if (ks[SDL_SCANCODE_DOWN] || ks[SDL_SCANCODE_S]) dy = 1;

        player.x += (int)(dx * speed * seconds);
        player.y += (int)(dy * speed * seconds);

        // clamp to window
        if (player.x < 0) player.x = 0;
        if (player.y < 0) player.y = 0;
        if (player.x + player.w > WINDOW_W) player.x = WINDOW_W - player.w;
        if (player.y + player.h > WINDOW_H) player.y = WINDOW_H - player.h;

        // render
        SDL_SetRenderDrawColor(ren, 30, 30, 40, 255);
        SDL_RenderClear(ren);

        // draw player
        //SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
        //SDL_RenderFillRect(ren, &player);

        sprite.mainLoop();

        //SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
        //SDL_Rect border = {10, 10, WINDOW_W - 20, WINDOW_H - 20};
        //SDL_RenderDrawRect(ren, &border);

        SDL_RenderPresent(ren);

        // small delay to avoid 100% CPU in case vsync is off
        SDL_Delay(1);
    }

  } // end mainLoop


}; // end class def

Sprite::Sprite(SDL_Renderer* ren){
  this->ren = ren;
  //this->rect = SDL_Rect;
  this->setSize(50, 50);
  this->setPosition(100, 100);
  this->setColor(255, 220, 20, 255);
} // end constructor

void Sprite::setSize(int width = 25, int height = 25){
  this->rect.w = width;
  this->rect.h = height;
} // end setSize

void Sprite::setPosition(int x = 100, int y = 100){
  this->rect.x = x;
  this->rect.y = y;
} // end setPosition

void Sprite::setColor(int r = 100, int g = 100, int b = 100, int a = 255){
  this->color.r = r;
  this->color.g = g;
  this->color.b = b;
  this->color.a = a;
} // end setColor

void Sprite::mainLoop(){
  this->process();
  SDL_SetRenderDrawColor(this->ren, this->color.r,
                                    this->color.g,
                                    this->color.b,
                                    this->color.a);

  SDL_RenderFillRect(this->ren, &(this->rect));
  
} // end mainLoop()

void Sprite::process(){
  // abstract method 
} // end process
 
int main(){
  Scene game;
}


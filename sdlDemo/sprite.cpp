#include <SDL2/SDL.h>
#include "sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* ren){
  this->ren = ren;
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
 
bool Sprite::isKeyPressed(SDL_Scancode key){
  //std::cout << "I got to isKeyPressed: " << key << std::endl;
  bool result = false; 
  SDL_PumpEvents();
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
  std::cout << "state: " << keyboardState[key] <<std::endl;
  if (keyboardState[key] == -1){
    result = true;
  } // end if
  return result;

} // end isKeyPressed


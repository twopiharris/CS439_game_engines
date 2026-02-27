#include <SDL2/SDL.h>
#include "sprite.h"
#include <iostream>

Sprite::Sprite(Scene* scene){
  this->scene = scene;
  this->ren = scene->getRen();
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
  SDL_SetRenderDrawColor(this->ren, this->color.r,
                                    this->color.g,
                                    this->color.b,
                                    this->color.a);
  this->process();
  this->checkBounds();

  SDL_RenderFillRect(this->ren, &(this->rect));
  
} // end mainLoop()

void Sprite::process(){
  // abstract method 
  // (normally - testing keyboard input for now)
  if (this->isKeyPressed(SDL_SCANCODE_RIGHT)){
    this->rect.x += 5;
  } // end if
  if (this->isKeyPressed(SDL_SCANCODE_LEFT)){
    this->rect.x -= 5;
  } // end if
  if (this->isKeyPressed(SDL_SCANCODE_UP)){
    this->rect.y -= 5;
  } // end if
  if (this->isKeyPressed(SDL_SCANCODE_DOWN)){
    this->rect.y += 5;
  } // end if
  
} // end process
 
bool Sprite::isKeyPressed(SDL_Scancode key){
  bool result = false; 
  //SDL_PumpEvents();
  const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
  if (keyboardState[key]){
    result = true;
  } // end if
  return result;
} // end isKeyPressed

void Sprite::checkBounds(){
  if (this->rect.x < 0){
    this->rect.x = this->scene->getWidth();
  } // end if
  if (this->rect.x > this->scene->getWidth()){
    this->rect.x = 0;;
  } // end if
  if (this->rect.y < 0){
    this->rect.y = this->scene->getHeight();
  } // end if
  if (this->rect.y > this->scene->getHeight()){
    this->rect.y = 0;
  } // end if
} // end checkBounds

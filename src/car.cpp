#include "car.h"
#include "graphics.h"

#include <iostream>

Car::Car() {}

Car::Car(Graphics &graphics)
    : AnimatedSprite(graphics, "res/elements/car.png", 0, 0, 400, 300, -150, 300, 100, 0.4) {
  graphics.loadImage("res/elements/car.png");
  this->recolorTexture();

  this->setupAnimations();
}

void Car::animationDone(std::string currentAnimation) {}

void Car::setupAnimations() {
  this->addAnimation(2, 0, 0, "", 400, 300, Vector2(0, 0));
}

void Car::update(float elapsedTime) {
  this->_x += 0.1 * elapsedTime;

  AnimatedSprite::update(elapsedTime);
}

// Red 12525102

void Car::recolorTexture() {
  // // initialize SDL, window, renderer, texture
  // int pitch, w, h;
  // void *pixels;

  // SDL_SetTextureBlendMode(this->_spriteSheet, SDL_BLENDMODE_BLEND);

  // SDL_QueryTexture(this->_spriteSheet, NULL, NULL, &w, &h);
  // SDL_LockTexture(this->_spriteSheet, NULL, &pixels, &pitch);
  // Uint32 *upixels = (Uint32 *)pixels;

  // // manipulate pixels
  // for (int i = 0; i < w * h; i++) {
  //   if (upixels[i] == 12525102) {
  //     upixels[i] = SDL_Color(rand() % 256, rand() % 256, rand() % 256, 255);
  //   }
  // }

  // // replace the old pixels with the new ones
  // memcpy(pixels, upixels, (pitch / 4) * h);

  // SDL_UnlockTexture(this->_spriteSheet);
}
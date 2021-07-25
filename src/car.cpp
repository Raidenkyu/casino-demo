#include "car.h"
#include "graphics.h"

#include <iostream>

Car::Car() {}

Car::Car(Graphics &graphics)
    : AnimatedSprite(graphics, "res/elements/car.png", 0, 0, 400, 300, -150, 300, 100, 0.4) {
  originalSurface = graphics.loadImage("res/elements/car.png");
  renderer = graphics.getRenderer();
  this->recolorTexture();

  this->setupAnimations();
}

void Car::animationDone(std::string currentAnimation) {}

void Car::setupAnimations() {
  this->addAnimation(2, 0, 0, "", 400, 300);
}

void Car::update(float elapsedTime) {
  if (this->state != MOVING) return;

  this->_x += 0.1 * elapsedTime;

  if (this->_x > globals::SCREEN_WIDTH) {
    this->state = FINISHED;
  }

  AnimatedSprite::update(elapsedTime);
}

void Car::start() {
  switch (this->state) {
    case MOVING:
      this->state = PAUSED;
      break;
    case PAUSED:
      this->state = MOVING;
      break;
    case FINISHED:
      this->_x = -150;
      this->_y = 300;

      this->recolorTexture();
      this->state = MOVING;
      break;

    default:
      break;
  }
}

void Car::recolorTexture() {
  SDL_Surface *surface = SDL_DuplicateSurface(originalSurface);

  Uint32 *pixels = (Uint32 *)surface->pixels;

  srand((unsigned)time(0));

  int newR = rand() % 0xFF;  // Random red gradient
  int newG = rand() % 0xFF;  // Random green gradient
  int newB = rand() % 0xFF;  // Random blue gradient

  for (int i = 0; i < surface->h * surface->w; i++) {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    uint32_t pixel = ((uint32_t *)surface->pixels)[i];
    SDL_GetRGB(pixel, surface->format, &r, &g, &b);

    if (r == 0xBF && g == 0x1E && b == 0x2E) {
      pixels[i] = SDL_MapRGB(surface->format, newR, newG, newB);
    }
  }

  this->_spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
}

CarState Car::getState() {
  return this->state;
}

bool Car::isFinished() {
  return (this->state == FINISHED);
}
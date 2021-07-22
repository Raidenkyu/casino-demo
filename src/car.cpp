#include "car.h"
#include "graphics.h"

Car::Car() {}

Car::Car(Graphics &graphics)
    : AnimatedSprite(graphics, "res/elements/car.png", 0, 0, 400, 300, -150, 300, 100, 0.4) {
  graphics.loadImage("res/elements/car.png");
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
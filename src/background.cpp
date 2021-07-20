#include "background.h"
#include "graphics.h"

Background::Background() {}

Background::Background(Graphics &graphics)
    : AnimatedSprite(graphics, "res/background/spritesheet.png", 0, 0, 500, 376, 0, 0, 70) {
  graphics.loadImage("res/background/spritesheet.png");
  this->setupAnimations();
}

void Background::animationDone(std::string currentAnimation) {}

void Background::setupAnimations() {
  this->addAnimation(13, 0, 0, "", 500, 376, Vector2(0, 0));
}
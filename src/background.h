#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "animatedsprite.h"

class Graphics;

class Background : public AnimatedSprite {
 public:
  Background();
  Background(Graphics &graphics);
  void draw(Graphics &graphics);
  void animationDone(std::string currentAnimation);
  void setupAnimations();
};

#endif

#ifndef CAR_H
#define CAR_H

#include "animatedsprite.h"

class Graphics;

class Car : public AnimatedSprite {
 public:
  Car();
  Car(Graphics &graphics);
  void draw(Graphics &graphics);
  void update(float elapsedTime);
  void animationDone(std::string currentAnimation);
  void setupAnimations();

 private:
  void recolorTexture(Graphics &graphics);
};

#endif

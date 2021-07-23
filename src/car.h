#ifndef CAR_H
#define CAR_H

#include "animatedsprite.h"

class Graphics;

enum CarState {
  MOVING,
  FINISHED,
  PAUSED
};

class Car : public AnimatedSprite {
 public:
  Car();
  Car(Graphics &graphics);

  void update(float elapsedTime);
  void animationDone(std::string currentAnimation);
  void setupAnimations();
  void start(Graphics &graphics);
  CarState getState();

 private:
  CarState state = FINISHED;

  void recolorTexture(Graphics &graphics);
};

#endif

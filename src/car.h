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
  void start();
  CarState getState();
  bool isFinished();

 private:
  CarState state = FINISHED;
  SDL_Surface *originalSurface;
  SDL_Renderer *renderer;

  void recolorTexture();
};

#endif

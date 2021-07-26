#ifndef CAR_H
#define CAR_H

#include "animatedsprite.h"

class Graphics;

/*
 * The different car states: The car is moving, the car finished its movement,
 * the car paused its movement.
 */
enum CarState {
  MOVING,
  FINISHED,
  PAUSED
};

/* Car Class
 * The animated car that moves when one coin is spent, and
 * its movement can be paused and resumed at any time. 
 */
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

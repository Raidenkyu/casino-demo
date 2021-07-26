#ifndef COINS_H
#define COINS_H

#include "animatedsprite.h"
#include "fonts.h"

class Graphics;

/* Coins Class
 * Counter of accumulated credits
 */
class Coins : public AnimatedSprite {
 public:
  Coins();
  Coins(Graphics &graphics, unsigned int *coinsCount);

  void animationDone(std::string currentAnimation);
  void setupAnimations();
  void draw(Graphics &graphics, Fonts &fonts);

 private:
  unsigned int *coinsCount;
};

#endif
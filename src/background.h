#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "animatedsprite.h"

class Graphics;

/* Background Class
 * The animated background of the game
 */
class Background : public AnimatedSprite {
 public:
  Background();
  Background(Graphics &graphics);

  void setupAnimations();
};

#endif

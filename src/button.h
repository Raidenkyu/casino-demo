#ifndef BUTTON_H
#define BUTTON_H

#include <memory>

#include "fonts.h"
#include "sprite.h"

/* AnimatedSprite Class
 * The base class of every button in the game
 */
class Button : public Sprite {
 public:
  Button();
  Button(Graphics& graphics, Fonts& fonts, std::string text, int x, int y, float textPadding = 0);

  void handleMouseEvent(Uint32 eventType, int x, int y, unsigned int& coinsCount);

 protected:
  bool pressed = false;
  unsigned int* coinsCount;

  virtual void buttonEffect(unsigned int& coinsCount) = 0;

 private:
};

#endif
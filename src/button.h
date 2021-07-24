#ifndef BUTTON_H
#define BUTTON_H

#include <memory>

#include "sprite.h"

class Button : public Sprite {
 public:
  Button();
  Button(Graphics& graphics, int x, int y);

  void handleMouseEvent(Uint32 eventType, int x, int y, unsigned int& coinsCount);

 protected:
  bool pressed = false;
  unsigned int* coinsCount;

  virtual void buttonEffect(unsigned int& coinsCount) = 0;

 private:
};

#endif
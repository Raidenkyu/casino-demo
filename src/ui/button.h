#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include "../sprite.h"

class Button : public Sprite {
 public:
  Button();
  Button(Graphics& graphics);

  void handleMouseEvent(Uint32 eventType, int x, int y);
  virtual void buttonEffect() = 0;

 protected:
  bool pressed = false;

 private:
};

#endif
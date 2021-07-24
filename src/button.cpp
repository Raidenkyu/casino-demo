#include "button.h"

Button::Button() {}

Button::Button(Graphics& graphics, int x, int y) : Sprite(graphics, "res/elements/button.png", 0, 0, 223, 106, x, y, 0.4),
                                                   coinsCount(coinsCount) {}

void Button::handleMouseEvent(Uint32 eventType, int x, int y, unsigned int& coinsCount) {
  bool horizontalMatch = x > this->_x && x < this->_x + this->_sourceRect.w * this->scale;
  bool verticalMatch = y > this->_y && y < this->_y + this->_sourceRect.h * this->scale;

  if (horizontalMatch && verticalMatch) {
    this->buttonEffect(coinsCount);
  }
}
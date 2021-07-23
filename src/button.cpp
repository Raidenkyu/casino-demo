#include "button.h"

Button::Button() {
}
Button::Button(Graphics& graphics) {
}

void Button::handleMouseEvent(Uint32 eventType, int x, int y) {
  bool horizontalMatch = x > this->_x && x < this->_x + this->_sourceRect.w * this->scale;
  bool verticalMatch = y > this->_y && y < this->_y + this->_sourceRect.h * this->scale;

  if (horizontalMatch && verticalMatch) {
    switch (eventType) {
      case SDL_MOUSEBUTTONDOWN:
        if (this->pressed) return;

        this->pressed = true;
        break;

      case SDL_MOUSEBUTTONUP:
        if (!this->pressed) return;

        this->pressed = true;

      default:
        break;
    }
  }
}
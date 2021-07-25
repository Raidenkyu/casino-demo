#include <SDL_ttf.h>
#include <iostream>

#include "button.h"
#include "graphics.h"

Button::Button() {}

Button::Button(Graphics& graphics, Fonts& fonts, std::string text, int x, int y, float textPadding) {
  this->_x = x;
  this->_y = y;
  this->scale = 0.45;

  this->_sourceRect.x = 0;
  this->_sourceRect.y = 0;
  this->_sourceRect.w = 223;
  this->_sourceRect.h = 106;

  SDL_Rect textRect;
  textRect.x = 15 + textPadding;
  textRect.y = 40;
  textRect.w = 223;
  textRect.h = 106;

  SDL_Surface* originalSurface = graphics.loadImage("res/elements/button.png");
  SDL_Surface* buttonSurface = SDL_DuplicateSurface(originalSurface);
  SDL_Surface* textSurface = fonts.generateText(text);
  SDL_BlitSurface(textSurface, NULL, buttonSurface, &textRect);

  SDL_FreeSurface(textSurface);

  this->_spriteSheet = SDL_CreateTextureFromSurface(
      graphics.getRenderer(), buttonSurface);

  if (_spriteSheet == NULL)
    std::cout << std::endl
              << "Error: Unable to load Image" << std::endl;
}

void Button::handleMouseEvent(Uint32 eventType, int x, int y, unsigned int& coinsCount) {
  bool horizontalMatch = x > this->_x && x < this->_x + this->_sourceRect.w * this->scale;
  bool verticalMatch = y > this->_y && y < this->_y + this->_sourceRect.h * this->scale;

  if (horizontalMatch && verticalMatch) {
    this->buttonEffect(coinsCount);
  }
}
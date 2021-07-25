#include "fonts.h"
#include <iostream>

Fonts::Fonts() {
  this->font = TTF_OpenFont("res/fonts/PressStart2P.ttf", 18);

  if (this->font == NULL) {
    std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
  }
}

Fonts::~Fonts() {}

SDL_Surface* Fonts::generateText(std::string text) {
  SDL_Color textColor = {255, 255, 255};
  return TTF_RenderText_Solid(this->font, text.c_str(), textColor);
}
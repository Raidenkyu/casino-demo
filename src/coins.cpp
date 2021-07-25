#include "coins.h"
#include "graphics.h"

Coins::Coins() {}

Coins::Coins(Graphics &graphics, unsigned int *coinsCount)
    : AnimatedSprite(graphics, "res/elements/coin.png", 0, 0, 256, 256, 270, 90, 80, 0.1), coinsCount(coinsCount) {
  this->setupAnimations();
}

void Coins::animationDone(std::string currentAnimation) {}

void Coins::setupAnimations() {
  this->addAnimation(8, 0, 0, "", 256, 256);
}

void Coins::draw(Graphics &graphics, Fonts &fonts) {
  // Draws coin animation
  AnimatedSprite::draw(graphics, this->_x, this->_y);

  // Creates the texture of the label with the current number of credits
  SDL_Surface *text = fonts.generateText(std::to_string(*(this->coinsCount)));
  SDL_Texture *texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), text);

  // The scale of the text in comparison to the coin
  float textScale = 0.7;

  // Rectangle to draw the label of credits count, in the window
  SDL_Rect destinationRectangle;
  destinationRectangle.x = this->_x - 15;
  destinationRectangle.y = this->_y + 5;
  destinationRectangle.w = this->_sourceRect.w * this->scale * textScale;
  destinationRectangle.h = this->_sourceRect.h * this->scale * textScale;

  // Draws label of credits count
  graphics.blitSurface(texture, NULL, &destinationRectangle);

  SDL_FreeSurface(text);
}
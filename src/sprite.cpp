#include <iostream>

#include "globals.h"
#include "graphics.h"
#include "sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filepath, int sourceX,
               int sourceY, int width, int height, float PosX, float PosY, float scale)
    : _x(PosX), _y(PosY), scale(scale) {
  // Source rectangle to locate the sprite in the spritesheet
  this->_sourceRect.x = sourceX;
  this->_sourceRect.y = sourceY;
  this->_sourceRect.w = width;
  this->_sourceRect.h = height;
  this->_spriteSheet = SDL_CreateTextureFromSurface(
      graphics.getRenderer(), graphics.loadImage(filepath));

  if (_spriteSheet == NULL)
    std::cout << std::endl
              << "Error: Unable to load Image" << std::endl;
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics) {
  this->draw(graphics, this->_x, this->_y);
}

void Sprite::draw(Graphics &graphics, int x, int y) {
  // Destination rectangle to draw in the window
  SDL_Rect destinationRectangel = {x, y,
                                   static_cast<int>(this->_sourceRect.w * this->scale),
                                   static_cast<int>(this->_sourceRect.h * this->scale)};

  // Draw the sprite in the window
  graphics.blitSurface(this->_spriteSheet, &this->_sourceRect,
                       &destinationRectangel);
}

void Sprite::update() {}
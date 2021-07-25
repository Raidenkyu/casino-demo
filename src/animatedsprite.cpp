#include "animatedsprite.h"
#include "globals.h"
#include "graphics.h"
#include "sprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filepath,
                               int sourceX, int sourceY, int width, int heigth,
                               float posX, float posY, float timeToUpdate, float scale)
    : Sprite(graphics, filepath, sourceX, sourceY, width, heigth, posX, posY, scale),
      _frameIndex(0),
      _timeElapsed(0),
      _timeToUpdate(timeToUpdate),
      _currentAnimation("") {}

void AnimatedSprite::playAnimation(std::string animation) {
  if (this->_currentAnimation != animation) {
    this->_currentAnimation = animation;
    _frameIndex = 0;
  }
}

void AnimatedSprite::update(float elapsedTime) {
  Sprite::update();
  this->_timeElapsed += elapsedTime;

  if (this->_timeElapsed > this->_timeToUpdate) {
    this->_timeElapsed -= this->_timeToUpdate;
    if ((this->_frameIndex) <
        (this->_animations[this->_currentAnimation].size() - 1)) {
      _frameIndex++;
    } else {
      this->_frameIndex = 0;
    }
  }
}

void AnimatedSprite::draw(Graphics &graphics) {
  this->draw(graphics, this->_x, this->_y);
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y) {
  SDL_Rect destinationRectangle;
  destinationRectangle.x = x;
  destinationRectangle.y = y;
  destinationRectangle.w = this->_sourceRect.w * this->scale;
  destinationRectangle.h = this->_sourceRect.h * this->scale;

  SDL_Rect sourceRect =
      this->_animations[this->_currentAnimation][this->_frameIndex];
  graphics.blitSurface(this->_spriteSheet, &sourceRect,
                       &destinationRectangle);
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name,
                                  int width, int heigth) {
  std::vector<SDL_Rect> rectangles;
  for (int i = 0; i < frames; i++) {
    SDL_Rect newRect = {(i + x) * width, y, width, heigth};
    rectangles.push_back(newRect);
  }
  this->_animations.insert(
      std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
}
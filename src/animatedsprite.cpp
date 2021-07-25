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
  // If the current animation is not the one we want to play, we will update it and reset the frame index
  if (this->_currentAnimation != animation) {
    this->_currentAnimation = animation;
    _frameIndex = 0;
  }
}

void AnimatedSprite::update(float elapsedTime) {
  Sprite::update();

  // Add to the accumulated elapsed time, the time passed since the last update
  this->_timeElapsed += elapsedTime;

  if (this->_timeElapsed > this->_timeToUpdate) {
    this->_timeElapsed -= this->_timeToUpdate;

    // Increments frame index and, if the current frame is the last one of the sequence, it is reseted
    this->_frameIndex = (this->_frameIndex + 1) % this->_animations[this->_currentAnimation].size();
  }
}

void AnimatedSprite::draw(Graphics &graphics) {
  this->draw(graphics, this->_x, this->_y);
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y) {
  // Selects a rectangle inside of the window to draw the sprite
  SDL_Rect destinationRectangle;
  destinationRectangle.x = x;
  destinationRectangle.y = y;
  destinationRectangle.w = this->_sourceRect.w * this->scale;
  destinationRectangle.h = this->_sourceRect.h * this->scale;

  // Selects rectangle that selects the current frame from the spritesheet
  SDL_Rect sourceRect =
      this->_animations[this->_currentAnimation][this->_frameIndex];

  // Draws the selected frame in the selected position of the window
  graphics.blitSurface(this->_spriteSheet, &sourceRect,
                       &destinationRectangle);
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name,
                                  int width, int heigth) {
  // The vector with every rectangle that selects every frame of the spritesheet
  std::vector<SDL_Rect> rectangles;

  // Generation of the rectangles
  for (int i = 0; i < frames; i++) {
    SDL_Rect newRect = {(i + x) * width, y, width, heigth};
    rectangles.push_back(newRect);
  }

  // Associates the vector of rectangles to a individual animation
  this->_animations.insert(
      std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
}
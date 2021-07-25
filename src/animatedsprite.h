#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <vector>

#include "globals.h"
#include "sprite.h"

class Graphics;

/* AnimatedSprite Class
 * Creates a sequence os sprites in a logic way to make an animaton
 */

class AnimatedSprite : public Sprite {
 public:
  AnimatedSprite();
  AnimatedSprite(Graphics &graphics, const std::string &filepath, int sourceX,
                 int sourceY, int width, int heigth, float posX, float posY,
                 float timeToUpdate, float scale = 1);
  void playAnimation(std::string animation);
  virtual void update(float elapsedTime);
  void draw(Graphics &graphics);
  void draw(Graphics &graphics, int x, int y);

 protected:
  double _timeToUpdate;
  std::string _currentAnimation;
  void addAnimation(int frames, int x, int y, std::string name, int width,
                    int heigth);

  virtual void setupAnimations() = 0;

 private:
  std::map<std::string, std::vector<SDL_Rect>> _animations;
  double _timeElapsed;
  int _frameIndex;
};

#endif

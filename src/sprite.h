#ifndef SPRITES_H
#define SPRITES_H

#include <SDL2/SDL.h>
#include <string>

class Graphics;

class Sprite {
 public:
  Sprite();
  Sprite(Graphics &graphics, const std::string &filepath, int sourceX,
         int sourceY, int width, int length, float PosX, float PosY, float scale = 1);
  virtual ~Sprite();
  void update();
  virtual void draw(Graphics &graphics, int x, int y);

 protected:
  SDL_Rect _sourceRect;
  SDL_Texture *_spriteSheet;
  float _x, _y;
  float scale;

 private:
};

#endif

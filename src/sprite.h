#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

class Graphics;

/* Sprite Class
 * Responsible for rendering sprites(with the help of graphics class) and
 * detecting their respective collisions
 */
class Sprite {
 public:
  Sprite();
  Sprite(Graphics &graphics, const std::string &filepath, int sourceX,
         int sourceY, int width, int length, float PosX, float PosY, float scale = 1);
  virtual ~Sprite();
  void update();
  virtual void draw(Graphics &graphics);
  virtual void draw(Graphics &graphics, int x, int y);

 protected:
  SDL_Rect _sourceRect;
  SDL_Texture *_spriteSheet;
  float _x, _y;
  float scale;

 private:
};

#endif

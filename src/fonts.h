#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>

class Fonts {
 public:
  Fonts();
  ~Fonts();
  SDL_Surface *generateText(std::string text);

 private:
  TTF_Font *font;
};

#endif
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

/* Graphics class
 * Responsible for the graphics for the game
 */
class Graphics {
 public:
  Graphics();
  ~Graphics();
  SDL_Surface *loadImage(const std::string &filepath);
  void blitSurface(SDL_Texture *source, SDL_Rect *rect_sourceRectangle,
                   SDL_Rect *rect_destinationRectangle);
  void flip();
  void clear();
  SDL_Renderer *getRenderer() const;

 private:
  SDL_Window *_window;
  SDL_Renderer *_renderer;
  std::map<std::string, SDL_Surface *> _spriteSheets;
};

#endif
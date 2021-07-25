#ifndef GAME_H
#define GAME_H

#include <SDL_mixer.h>
#include <memory>
#include <vector>

#include "animatedsprite.h"
#include "button.h"
#include "car.h"
#include "coins.h"
#include "fonts.h"

class Graphics;

class Game {
 public:
  Game();
  ~Game();

 private:
  // Game Data
  std::vector<std::shared_ptr<AnimatedSprite>> _gameSprites;
  std::vector<std::shared_ptr<Button>> buttons;
  std::shared_ptr<Car> car;
  std::shared_ptr<Coins> coins;
  Mix_Music *themeTrack;

  unsigned int coinsCount = 0;

  // Game Loop
  void gameLoop();
  void draw(Graphics &graphics, Fonts &fonts);
  void update(float elapsedTime);

  // Game Setup
  void initGameElements(Graphics &graphics, Fonts &fonts);
};

#endif

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "animatedsprite.h"
#include "car.h"
#include "ui/button.h"


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

  // Game Loop
  void gameLoop();
  void draw(Graphics &graphics);
  void update(float elapsedTime);

  // Game Setup
  void initGameElements(Graphics &graphics);
};

#endif

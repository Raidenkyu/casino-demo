#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <algorithm>

/* Game Class
 * The "Game" class where the game loop runs
 */

namespace {
// Limit of FPS
const int FPS = 50;
const int MAX_FRAME = 5 * 1000 / FPS;
} // namespace

Game::Game() {
  SDL_Init(SDL_INIT_EVERYTHING);
  this->gameLoop();
}

Game::~Game() {}

void Game::gameLoop() {
  // Setting up data before begining the loop/game
  Graphics graphics;
  SDL_Event event;
  //this->_player = Player(graphics, 100, 100);
  int LAST_TIME_UPDATE = SDL_GetTicks();

  // Start Game Loop
  while (true) {
      if (event.type == SDL_QUIT)
        return;
    }

  const int CURRENT_TIME_MS = SDL_GetTicks();
  int ELSAPSED_TIME_MS = CURRENT_TIME_MS - LAST_TIME_UPDATE;
  this->update(std::min(ELSAPSED_TIME_MS, MAX_FRAME));
  LAST_TIME_UPDATE = CURRENT_TIME_MS;
  this->draw(graphics);
}


void Game::draw(Graphics &graphics) {
  graphics.clear();
  //this->_player.draw(graphics);
  graphics.flip();
}

void Game::update(float elapsedTime) { 
  //this->_player.update(elapsedTime);
}
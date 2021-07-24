#include <SDL2/SDL.h>
#include <algorithm>
#include <memory>

#include "background.h"
#include "creditsInButton.h"
#include "creditsOutButton.h"
#include "fonts.h"
#include "game.h"
#include "graphics.h"
#include "startButton.h"

/* Game Class
 * The "Game" class where the game loop runs
 */

// Define Framerate
namespace {
  const int FPS = 50;
  const int MAX_FRAME = 5 * 1000 / FPS;
}

Game::Game() {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  this->gameLoop();
}

Game::~Game() {}

void Game::gameLoop() {
  // Setting up data before begining the loop/game
  Graphics graphics;
  Fonts fonts;
  SDL_Event event;
  initGameElements(graphics, fonts);

  // Start Tick Counter
  int LAST_TIME_UPDATE = SDL_GetTicks();

  // Game Loop
  while (true) {
    // Poll for an SDL Event
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        return;

      if (event.type == SDL_MOUSEBUTTONDOWN) {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        for (auto &button : this->buttons) {
          button->handleMouseEvent(event.type, x, y, coinsCount);
        }
      }
    }

    // Calculate Elapsed Time
    const int CURRENT_TIME_MS = SDL_GetTicks();
    int ELSAPSED_TIME_MS = CURRENT_TIME_MS - LAST_TIME_UPDATE;

    // Update Game State
    this->update(std::min(ELSAPSED_TIME_MS, MAX_FRAME));

    LAST_TIME_UPDATE = CURRENT_TIME_MS;

    // Draw the current Game Frame
    this->draw(graphics);
  }
}

void Game::draw(Graphics &graphics) {
  graphics.clear();

  for (auto &sprite : this->_gameSprites) {
    sprite->draw(graphics);
  }

  for (auto &button : this->buttons) {
    button->draw(graphics);
  }

  graphics.flip();
}

void Game::update(float elapsedTime) {
  for (auto &sprite : this->_gameSprites) {
    sprite->update(elapsedTime);
  }
}

void Game::initGameElements(Graphics &graphics, Fonts &fonts) {
  this->_gameSprites.push_back(
      std::make_shared<Background>(graphics));

  this->car = std::make_shared<Car>(graphics);

  this->_gameSprites.push_back(this->car);

  this->buttons.push_back(std::make_shared<CreditsInButton>(graphics, fonts));
  this->buttons.push_back(std::make_shared<CreditsOutButton>(graphics, fonts));
  this->buttons.push_back(std::make_shared<StartButton>(graphics, fonts, this->car.get()));
}
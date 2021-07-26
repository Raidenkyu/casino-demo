#include "startButton.h"

StartButton::StartButton(){};

StartButton::StartButton(Graphics& graphics, Fonts& fonts, Car* car) : Button(graphics, fonts, "START", 310, 10, 50), car(car) {
}

void StartButton::buttonEffect(unsigned int& coinsCount) {
  if (!this->car->isFinished()) {
    // If the movement is not finished, no credit is spent
    this->car->start();
  } else if (coinsCount > 0) {
    // When the animation is finished and there are credits, a credit is spent to start another animation
    coinsCount--;
    this->car->start();
  }
}
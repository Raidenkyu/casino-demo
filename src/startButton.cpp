#include "startButton.h"

StartButton::StartButton(){};

StartButton::StartButton(Graphics& graphics, Fonts& fonts, Car* car) : Button(graphics, fonts, "START", 310, 10, 50), car(car) {
}

void StartButton::buttonEffect(unsigned int& coinsCount) {
  if (!this->car->isFinished()) {
    this->car->start();
  } else if (coinsCount > 0) {
    coinsCount--;
    this->car->start();
  }
}
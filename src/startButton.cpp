#include "startButton.h"

StartButton::StartButton(){};

StartButton::StartButton(Graphics& graphics, Car* car) : Button(graphics, 300, 10), car(car) {
}

void StartButton::buttonEffect(unsigned int& coinsCount) {
  if (!this->car->isFinished()) {
    this->car->start();
  }
  if (coinsCount > 0) {
    coinsCount--;
    this->car->start();
  }
}
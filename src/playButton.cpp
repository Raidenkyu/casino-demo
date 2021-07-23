#include "playButton.h"

#include <iostream>

PlayButton::PlayButton(){};

PlayButton::PlayButton(Graphics& graphics) : Button(graphics) {
}

void PlayButton::buttonEffect(unsigned int& coinsCount) {
  coinsCount++;
  std::cout << coinsCount << std::endl;
}
#include "creditsInButton.h"

CreditsInButton::CreditsInButton(){};

CreditsInButton::CreditsInButton(Graphics& graphics, Fonts& fonts) : Button(graphics, fonts, "CREDITS IN", 90, 10) {
  this->soundEffect = Mix_LoadWAV("res/sound/coin.wav");
}

void CreditsInButton::buttonEffect(unsigned int& coinsCount) {
  coinsCount++;
  Mix_PlayChannel(-1, this->soundEffect, 0);
}
#include "creditsInButton.h"

CreditsInButton::CreditsInButton(){};

CreditsInButton::CreditsInButton(Graphics& graphics, Fonts& fonts) : Button(graphics, fonts, "CREDITS IN", 100, 10) {
}

void CreditsInButton::buttonEffect(unsigned int& coinsCount) {
  coinsCount++;
}
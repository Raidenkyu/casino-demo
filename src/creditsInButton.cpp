#include "creditsInButton.h"

CreditsInButton::CreditsInButton(){};

CreditsInButton::CreditsInButton(Graphics& graphics) : Button(graphics, 100, 10) {
}

void CreditsInButton::buttonEffect(unsigned int& coinsCount) {
  coinsCount++;
}
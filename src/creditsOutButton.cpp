#include "creditsOutButton.h"

CreditsOutButton::CreditsOutButton(){};

CreditsOutButton::CreditsOutButton(Graphics& graphics, Fonts& fonts) : Button(graphics, fonts, "CREDITS OUT", 200, 10) {
}

void CreditsOutButton::buttonEffect(unsigned int& coinsCount) {
  if (coinsCount > 0) {
    coinsCount--;
  }
}
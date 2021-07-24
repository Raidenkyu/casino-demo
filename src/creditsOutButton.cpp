#include "creditsOutButton.h"

CreditsOutButton::CreditsOutButton(){};

CreditsOutButton::CreditsOutButton(Graphics& graphics) : Button(graphics, 200, 10) {
}

void CreditsOutButton::buttonEffect(unsigned int& coinsCount) {
  if (coinsCount > 0) {
    coinsCount--;
  }
}
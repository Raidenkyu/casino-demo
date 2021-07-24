#ifndef CREDITS_IN_BUTTON_H
#define CREDITS_IN_BUTTON_H

#include "button.h"

class CreditsInButton : public Button {
 public:
  CreditsInButton();
  CreditsInButton(Graphics& graphics);

 private:
  void buttonEffect(unsigned int& coinsCount);
};

#endif
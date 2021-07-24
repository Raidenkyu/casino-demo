#ifndef CREDITS_OUT_BUTTON_H
#define CREDITS_OUT_BUTTON_H

#include "button.h"

class CreditsOutButton : public Button {
 public:
  CreditsOutButton();
  CreditsOutButton(Graphics& graphics);

 private:
  void buttonEffect(unsigned int& coinsCount);
};

#endif
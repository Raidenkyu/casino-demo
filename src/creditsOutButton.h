#ifndef CREDITS_OUT_BUTTON_H
#define CREDITS_OUT_BUTTON_H

#include "button.h"

/* CreditsOutButton Class
 * The button to remove credits
 */
class CreditsOutButton : public Button {
 public:
  CreditsOutButton();
  CreditsOutButton(Graphics& graphics, Fonts& fonts);

 private:
  void buttonEffect(unsigned int& coinsCount);
};

#endif
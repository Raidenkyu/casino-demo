#ifndef CREDITS_IN_BUTTON_H
#define CREDITS_IN_BUTTON_H

#include <SDL_mixer.h>

#include "button.h"

class CreditsInButton : public Button {
 public:
  CreditsInButton();
  CreditsInButton(Graphics& graphics, Fonts& fonts);

 private:
  Mix_Chunk* soundEffect;

  void buttonEffect(unsigned int& coinsCount);
};

#endif
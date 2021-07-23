#ifndef PLAY_BUTTON_H
#define PLAY_BUTTON_H

#include "button.h"

class PlayButton : public Button {
 public:
  PlayButton();
  PlayButton(Graphics& graphics);

 private:
  void buttonEffect(unsigned int& coinsCount);
};

#endif
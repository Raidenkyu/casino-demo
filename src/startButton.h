#ifndef START_BUTTON_H
#define START_BUTTON_H

#include "button.h"
#include "car.h"

class StartButton : public Button {
 public:
  StartButton();
  StartButton(Graphics& graphics, Car* car);

 private:
  Car* car;

  void buttonEffect(unsigned int& coinsCount);
};

#endif
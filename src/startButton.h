#ifndef START_BUTTON_H
#define START_BUTTON_H

#include "button.h"
#include "car.h"

/* StartButton Class
 * The button that spents one credit to start the animation of the car
 */
class StartButton : public Button {
 public:
  StartButton();
  StartButton(Graphics& graphics, Fonts& fonts, Car* car);

 private:
  Car* car;

  void buttonEffect(unsigned int& coinsCount);
};

#endif
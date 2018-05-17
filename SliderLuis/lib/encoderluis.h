#include <Arduino.h>
#include "screenluis.h"
#include "motorluis.h"

class Encoder{
  public:
    Encoder(Screen* screen, Motor* motor);
    void clockWise();
    void counterClockWise();
    void button();
    void drawSubmenu();
  private:
    Screen* screen_;
    Motor* motor_;
    unsigned long int time_;
    int changeTime_;

};

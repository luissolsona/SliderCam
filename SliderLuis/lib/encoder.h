#include <Arduino.h>
#include "pantalla.h"
#include "motor.h"

class Encoder{
  public:
    Encoder(Screen* screen, Motor* motor);
    void giroDerecha();
    void giroIzquierda();
    void presBoton();
    void dibujaSubmenu();
  private:
    Screen* screen_;
    Motor* motor_;
    unsigned long int time_;
    int changeTime_;

};

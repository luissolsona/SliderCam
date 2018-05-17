#include <Arduino.h>
#include <encoder.h>

Screen screen;
Motor motor(5, 6, 7);
Encoder encoder(&screen, &motor);
static boolean rotating=false;

void rotEncoder()
{
  rotating=true; // If motion is detected in the rotary encoder,
                 // set the flag to true
}

void clk(){
  encoder.clockWise();
}
void dt(){
  encoder.counterClockWise();
}

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT);

  attachInterrupt(0, rotEncoder, CHANGE);
//  attachInterrupt(1, dt, FALLING);

  screen.set();
  screen.menu();
}

void loop() {
  if(digitalRead(4) == LOW){
    encoder.button();
    delay(10);
  }
while(rotating)
  {
    delay(2);  // debounce by waiting 2 milliseconds
               // (Just one line of code for debouncing)
    if (digitalRead(3) == digitalRead(2))  // CCW
      clk();
    else                          // If not CCW, then it is CW
      dt();

    rotating=false; // Reset the flag

  }

  motor.move();
  if(motor.getFinished()){
    encoder.drawSubmenu();
    motor.setFinished(false);
  }
}

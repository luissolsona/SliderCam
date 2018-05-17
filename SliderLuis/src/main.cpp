/*
#include <Arduino.h>
#include <encoderluis.h>

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
*/

#include <Arduino.h>
#include "test.h"

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(LED_BUILTIN, 13);
}

void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // IMPORTANT LINE!
    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); // stop unit testing
    }
}

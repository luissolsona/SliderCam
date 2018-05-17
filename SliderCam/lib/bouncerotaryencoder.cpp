static boolean rotating=false;
void rotEncoder()
{
  rotating=true; // If motion is detected in the rotary encoder,
                 // set the flag to true
}
...

void setup() {

  // Attach Interrupts
  attachInterrupt(0, rotEncoder, CHANGE);  // ISR for rotary encoder
  ...
  ...
}

void loop() {
  ...

   while(rotating)
  {
    delay(2);  // debounce by waiting 2 milliseconds
               // (Just one line of code for debouncing)
    if (digitalRead(4) == digitalRead(2))  // CCW
    ...
    else                          // If not CCW, then it is CW
    ...

    rotating=false; // Reset the flag

  }
}

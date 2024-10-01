#include <Adafruit_NeoPixel.h>

#define PIN 4         // Pin connected to the data line of the LED strip
#define NUM_LEDS 50   // Number of LEDs in the strip
#define BUTTON_PIN 6  // Pin connected to the button

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

bool ledsLit[NUM_LEDS] = {false};  // Track which LEDs have already been lit
bool buttonPressed = false;        // Track button state

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button setup (active LOW)
  strip.begin();                      // Initialize the LED strip
  strip.show();                       // Turn off all the LEDs initially
  randomSeed(analogRead(0));          // Random seed based on an analog read
}

void loop() {
  for (int i = 0; i < NUM_LEDS ; i++){
    delay(100);
    strip.setPixelColor(i , 0, 255 , 255);
    strip.show();
  }
  for (int i = 0; i < NUM_LEDS ; i++){
    delay(100);
    strip.setPixelColor(i , 0, 0 , 0);
    strip.show();
  }
}

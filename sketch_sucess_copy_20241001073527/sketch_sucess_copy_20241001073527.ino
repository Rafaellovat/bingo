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
  if (digitalRead(BUTTON_PIN) == LOW && !buttonPressed) {
    delay(50);  // Debounce delay

    int randomLED;
    do {
      randomLED = random(0, NUM_LEDS);  // Get a random LED index
    } while (ledsLit[randomLED]);       // Make sure the LED hasn't been lit yet

    ledsLit[randomLED] = true;          // Mark the LED as lit
    strip.setPixelColor(randomLED, strip.Color(255, 0, 0));  // Turn on the LED (red color)
    strip.show();                       // Display the new LED state

    buttonPressed = true;               // Mark button as pressed
  }

  if (digitalRead(BUTTON_PIN) == HIGH) {
    buttonPressed = false;  // Reset button state when released
  }
}

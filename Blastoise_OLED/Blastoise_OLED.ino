
/*
  Blastoise OLED Animation
  Arduino Uno
  OLED: SSD1306 128x64 I2C
  Button: D2
  Passive buzzer: D8 
  */


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "blastoise.h"

// Hardware
const uint8_t BTN_PIN = 2;
const uint8_t BUZZ_PIN = 8;
const uint8_t OLED_ADDR = 0x3C;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Sprite position
const int SPRITE_X = 32;
const int SPRITE_Y = 0;

// Animation timing
const int STEPS = 40;
const int STEP_MS = 10;
const int FLIP_EVERY = 10;


// Draw one of the two Blastoise frames
void showFrame(uint8_t frame) {
  display.clearDisplay();

  display.drawBitmap(
    SPRITE_X,
    SPRITE_Y,
    frame ? blastoise_bmp1 : blastoise_bmp0,
    64,
    64,
    SSD1306_WHITE
  );

  display.display();
}


// Play the cry while animating
void playBlastoise() {

  for (int i = 0; i < STEPS; i++) {

    
    if (i % FLIP_EVERY == 0) {
      showFrame((i / FLIP_EVERY) % 2 == 0 ? 1 : 0);
    }

    int hz;

    if (i < 10) {

      // Growl 1
      hz = random(65, 115);

      if (i % 3 == 0) {
        tone(BUZZ_PIN, hz);
        delay(5);
        noTone(BUZZ_PIN);
        delay(5);
      } else {
        tone(BUZZ_PIN, hz);
        delay(10);
      }

    }
    else if (i < 25) {

      // Growl 2
      hz = random(75, 125);

      if (i % 2 == 0) {
        tone(BUZZ_PIN, hz);
        delay(5);
        noTone(BUZZ_PIN);
        delay(5);
      } else {
        tone(BUZZ_PIN, hz + random(-15, 16));
        delay(10);
      }

    }
    else {

      // Growl 3
      int progress = i - 25;

      hz = 180 - progress * 7;
      hz += random(-30, 31);

      tone(BUZZ_PIN, max(55, hz));

      if (i % 4 == 0) {
        delay(7);
        noTone(BUZZ_PIN);
        delay(3);
      } else {
        delay(10);
      }
    }
  }

  noTone(BUZZ_PIN);
  showFrame(0);
}


void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(BUZZ_PIN, OUTPUT);

  randomSeed(analogRead(A0));

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    while (true) {
      delay(100);
    }
  }

  showFrame(0);
}


void loop() {

  if (digitalRead(BTN_PIN) == LOW) {

    playBlastoise();

    while (digitalRead(BTN_PIN) == LOW) {
      delay(5);
    }

    delay(30);
  }
}

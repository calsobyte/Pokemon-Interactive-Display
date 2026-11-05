# Build notes

## 1. Install the libraries

In Arduino IDE, open **Tools → Manage Libraries** and install:

- Adafruit GFX Library
- Adafruit SSD1306

## 2. Set up the sketch folder

Arduino IDE expects the main `.ino` file to be inside a folder with the same name. For example:

```text
BlastoiseOLED/
├── BlastoiseOLED.ino
└── blastoise.h
```

Paste your final Arduino sketch into `BlastoiseOLED.ino` and copy `src/blastoise.h` from this repository beside it. The sketch includes the header with:

```cpp
#include "blastoise.h"
```

## 3. Check the OLED address

The sketch currently uses `0x3C`, which is what my OLED read as. If the display doesn't run do an I2C check, your module might be read as a '0x3D'.

## 4. Upload and test

Upload to an Arduino Uno. The OLED should show the idle frame at startup. Press the button to play the cry and the short animation, after about half a second it should return to the original pose

## Troubleshooting

- **OLED stays blank:** Check SDA/SCL, power, GND, and the I²C address.
- **Bitmap does not compile:** Make sure `blastoise.h` is beside the `.ino` file and that the array names match the sketch.
- **Buzzer is silent:** Confirm it is a passive buzzer (Open at the bottom, you can see the ciruit), check polarity and GND, and test it with a short `tone()` example.
- **Button triggers continuously:** Check that the button is between D2 and GND and that the sketch uses `INPUT_PULLUP`.

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

The sketch currently uses `0x3C`. If the display does not initialize, run an I²C scanner and check whether the module responds at `0x3D`.

## 4. Upload and test

Upload to an Arduino Uno. The OLED should show the idle frame at startup. Press the button to play the cry and animation; after the effect ends, the display should return to the idle frame.

## Troubleshooting

- **OLED stays blank:** Check SDA/SCL, power, GND, and the I²C address.
- **Bitmap does not compile:** Make sure `blastoise.h` is beside the `.ino` file and that the array names match the sketch.
- **Buzzer is silent:** Confirm it is a passive buzzer, check polarity and GND, and test it with a short `tone()` example.
- **Button triggers continuously:** Check that the button is between D2 and GND and that the sketch uses `INPUT_PULLUP`.

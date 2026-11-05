# Parts list

| Part | Quantity | Notes |
|---|---:|---|
| Arduino Uno | 1 | Main controller |
| SSD1306 I²C OLED, 128×64 | 1 | Usually has GND, VCC, SCL, and SDA pins |
| Passive buzzer | 1 | Not an active buzzer; driven with `tone()` |
| Momentary push button | 1 | Starts the animation and cry |
| Breadboard | 1 | For temporary assembly |
| Jumper wires | As needed | Male-to-male and Male-to-female|
| USB cable for Arduino Uno | 1 | Programming and power |

## Optional

- A multimeter for checking connections.
- A separate regulated supply if your setup later needs more current. Keep all grounds common. (Shouldn't be needed for this project)

## Notes

- The button is wired using the Uno's internal pull-up (`INPUT_PULLUP`), so a separate pull-up resistor is not required.
- Check the OLED module's rated supply voltage before connecting VCC. Many breakout boards accept 5 V, but not every module does.
- Do not assume every buzzer module has the same pin labels. Check its markings.

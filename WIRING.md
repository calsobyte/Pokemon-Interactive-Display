# Wiring

Connections for the current Arduino Uno sketch.

## OLED (SSD1306 I²C, 128×64)

| OLED pin | Arduino Uno |
|---|---|
| GND | GND |
| VCC | 5V or 3.3V, according to the OLED module's rating |
| SDA | A4 |
| SCL | A5 |

## Push button

| Button terminal | Arduino Uno |
|---|---|
| One side | D2 |
| Other side | GND |

The sketch uses `INPUT_PULLUP`. The button reads HIGH when released and LOW when pressed.

## Passive buzzer

| Buzzer terminal | Arduino Uno |
|---|---|
| Positive (+) | D8 |
| Negative (−) | GND |

If the buzzer is an unmarked piezo element, check its datasheet or test its terminals. Avoid connecting an unknown buzzer module by guesswork.

## Quick pin summary

- OLED SDA: A4
- OLED SCL: A5
- Button: D2
- Passive buzzer: D8

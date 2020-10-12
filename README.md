# led-candle

Simulate a flickering candle with an LED.  Or two.  Or ten.

This library _only_ handles the math and timing.  It is up to you to implement an LED that suits your implementation.  You can do anything you like.  You might want to use this with an RGB LED.  Or you might want to use it with a single warm white LED.  You can even use an entire string of addressable LEDs and simulate a raging inferno.

## Usage

### With an RGB LED

The most basic example doesn't require any additional hardware for a Particle device with an on-board RGB LED to simulate a tiny flickering flame:

```
#include "led-candle.h"

LedCandle rgbLedCandle;

void setup() {
	RGB.control(true);
}

void loop() {
	RGB.color(rgbLedCandle.getColour());
}
```

### With a single LED on a PWM pin

Connect an LED and a resistor to Pin D2, and try this:

```
#include "led-candle.h"

#define PIN_MONOCHROMATIC_LED D2

LedCandle monochromaticLedCandle;

void setup() {
	// Pick a PWM-capable pin.
	pinMode(PIN_MONOCHROMATIC_LED, OUTPUT);
	analogWrite(PIN_MONOCHROMATIC_LED, 0);
}

void loop() {
	analogWrite(PIN_MONOCHROMATIC_LED, monochromaticLedCandle.getMonochromaticValue());
}
```

See the [examples](examples) folder for more details.

## Configuration

You can override any of the default configuration with `#define` statements, before `#include "led-candle.h"`.

### Options

| Name | Default Value | Description |
|------|---------------|---------|
| `LEDCANDLE_BRIGHTNESS_BOTTOM_PERCENT` | `10`  | Percent chance the LED will suddenly fall to minimum brightness |
| `LEDCANDLE_BRIGHTNESS_BOTTOM`         | `128` | Absolute minimum brightness value |
| `LEDCANDLE_BRIGHTNESS_MIN`            | `128` | Minimum brightness value during "normal" flickering |
| `LEDCANDLE_BRIGHTNESS_MAX`            | `255` | Maximum brightness value |
| `LEDCANDLE_DOWN_MIN_MSECS`            | `20`  | Decreasing brightness will take place over a number of milliseconds in this range |
| `LEDCANDLE_DOWN_MAX_MSECS`            | `250` | Decreasing brightness will take place over a number of milliseconds in this range |
| `LEDCANDLE_UP_MIN_MSECS`              | `20`  | Increasing brightness will take place over a number of milliseconds in this range |
| `LEDCANDLE_UP_MAX_MSECS`              | `250` | Increasing brightness will take place over a number of milliseconds in this range |
| `LEDCANDLE_BRIGHT_HOLD_PERCENT`       | `20`  | Percent chance the color will hold unchanged after brightening |
| `LEDCANDLE_BRIGHT_HOLD_MIN_MSECS`     | `0`   | When holding after brightening, hold for a number of milliseconds in this range |
| `LEDCANDLE_BRIGHT_HOLD_MAX_MSECS`     | `100` | When holding after brightening, hold for a number of milliseconds in this range |
| `LEDCANDLE_DIM_HOLD_PERCENT`          | `5`   | Percent chance the color will hold unchanged after dimming |
| `LEDCANDLE_DIM_HOLD_MIN_MSECS`        | `0`   | When holding after dimming, hold for a number of milliseconds in this range |
| `LEDCANDLE_DIM_HOLD_MAX_MSECS`        | `50`  | When holding after dimming, hold for a number of milliseconds in this range |

### Example

For a dramatic flickering effect, adjust the minimum brightness:

```
#define LEDCANDLE_BRIGHTNESS_BOTTOM 25
#define LEDCANDLE_BRIGHTNESS_MIN 25

#include "led-candle.h"

// ...etc
```

## Attribution

This library builds upon [code from Adafruit's Learning System](https://github.com/adafruit/Adafruit_Learning_System_Guides/tree/master/LED_Candles).
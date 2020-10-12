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

## Attribution

This library builds upon [code from Adafruit's Learning System](https://github.com/adafruit/Adafruit_Learning_System_Guides/tree/master/LED_Candles).
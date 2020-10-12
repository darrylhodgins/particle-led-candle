/**
 * The library provides defaults that look decent to my eyes, but you can
 * override those if you like.
 * 
 * Use #define _before_ including `led-candle.h` to do this.
 * 
 * For example:
 */
#define LEDCANDLE_BRIGHTNESS_BOTTOM 25
#define LEDCANDLE_BRIGHTNESS_MIN 92

#include "led-candle.h"

LedCandle rgbLedCandle;
LedCandle rgLedCandle;
LedCandle monochromaticLedCandle;

#define PIN_MONOCHROMATIC_LED D2
#define PIN_RG_LED_RED D0
#define PIN_RG_LED_GREEN D1

void setup() {

 	// This is a demonstration using the on-board RGB LED.
	// You could easily use a NeoPixel or plain RGB LED if you want.
	RGB.control(true);

	// For monochromatic output, pick a PWM-capable pin.
	pinMode(PIN_MONOCHROMATIC_LED, OUTPUT);
	analogWrite(PIN_MONOCHROMATIC_LED, 0);

	// The library only uses the red and green, so you could also use a bicolour red + green LED.
	// Again, pick PWM-capable pins.
	pinMode(PIN_RG_LED_RED, OUTPUT);
	pinMode(PIN_RG_LED_GREEN, OUTPUT);
	analogWrite(PIN_RG_LED_RED, 0);
	analogWrite(PIN_RG_LED_GREEN, 0);
}

// Temp variables
uint8_t r, g, b, val;
uint32_t colour;

void loop() {

	// RGB option 1: Get the candle colour as a convenient uint32_t in RGB order:
	colour = rgbLedCandle.getColour();
	RGB.color(colour);

	// RGB option 2: If a packed 32-bit int isn't convenient enough for you, you can get the individual values:
	rgbLedCandle.getRgb(&r, &g, &b);
	RGB.color(r, g, b);

	// If colour isn't your thing, a warm white LED works nicely:
	val = monochromaticLedCandle.getMonochromaticValue();
	analogWrite(PIN_MONOCHROMATIC_LED, val);

	// Or try that with some bicolour LEDs.  Blue is always 0 anyway, so we'll ignore it:
	rgLedCandle.getRgb(&r, &g, &b);
	analogWrite(PIN_RG_LED_RED, r);
	analogWrite(PIN_RG_LED_GREEN, g);
}

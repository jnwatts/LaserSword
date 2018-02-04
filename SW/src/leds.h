#ifndef LEDS_H
#define LEDS_H

typedef enum {
	LEDS_OFF = 0,
	LEDS_RED = (1u<<0),
	LEDS_BLUE = (1u<<1),
	LEDS_PURPLE = LEDS_RED | LEDS_BLUE,

	LEDS_FIRST = LEDS_RED,
	LEDS_LAST = LEDS_PURPLE,
} leds_color_t;

void Leds_Init(void);
void Leds_Think(void);

void Leds_SetColor(leds_color_t color);

#endif
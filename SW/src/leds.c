#include <stdbool.h>

#include <fsl_gpio.h>

#include "leds.h"
#include "board.h"

typedef struct {
	leds_color_t color;
} leds_t;
leds_t g_leds;

static inline void Leds_SetL1(void) { GPIO_PinWrite(BOARD_L1_UP_PORT, BOARD_L1_UP_PIN, 1); }
static inline void Leds_SetL2(void) { GPIO_PinWrite(BOARD_L2_UP_PORT, BOARD_L2_UP_PIN, 1); }
static inline void Leds_ClearL1(void) { GPIO_PinWrite(BOARD_L1_UP_PORT, BOARD_L1_UP_PIN, 0); }
static inline void Leds_ClearL2(void) { GPIO_PinWrite(BOARD_L2_UP_PORT, BOARD_L2_UP_PIN, 0); }

void Leds_Init(void)
{
	gpio_pin_config_t pin_config = {
		.pinDirection = kGPIO_DigitalOutput,
		.outputLogic = 0,
	};

	GPIO_PinInit(BOARD_L1_UP_PORT, BOARD_L1_UP_PIN, &pin_config);
	GPIO_PinInit(BOARD_L2_UP_PORT, BOARD_L2_UP_PIN, &pin_config);
}

void Leds_Think(void)
{
	if (g_leds.color == LEDS_OFF) {
		Leds_ClearL1();
		Leds_ClearL2();
	} else {
		if (g_leds.color & LEDS_RED)
			Leds_SetL1();
		else
			Leds_ClearL1();

		if (g_leds.color & LEDS_BLUE)
			Leds_SetL2();
		else
			Leds_ClearL2();
	}
}

void Leds_SetColor(leds_color_t color)
{
	g_leds.color = color;
}

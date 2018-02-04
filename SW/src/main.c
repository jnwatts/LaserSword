#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "leds.h"
#include "buttons.h"
#include "timer.h"

#ifdef DEBUG
//TODO: Trim fat of debug console, else we currently over-shoot flash size by 50%
#include <fsl_debug_console.c>
#define DBG PRINTF
#else
#define DBG(...)
#define DBG(...)
#endif

delay_button_t sw1_delay_button = {
	.read_state = ReadSW1State,
	.counter = 0,
};

leds_color_t led_color = LEDS_PURPLE;
uint32_t leds_color_changed = 0;

int main(void)
{

	/* Init board hardware */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	Timer_Init();

	Buttons_Init();
	Leds_Init();

	while (1) {
		if (Timer_Ready()) {
			if (Delay_Button_Value(&sw1_delay_button) >= 50) { // 500ms
				led_color++;
				if (led_color > LEDS_LAST)
					led_color = LEDS_FIRST;
				leds_color_changed = 100; // 1s
			}

			if (ReadL1State() || ReadL2State() || leds_color_changed > 0) {
				Leds_SetColor(led_color);
			} else {
				Leds_SetColor(LEDS_OFF);
			}

			Leds_Think();

			if (leds_color_changed > 0)
				--leds_color_changed;
		}
	}
}
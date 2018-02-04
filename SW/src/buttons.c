#include "buttons.h"
#include "board.h"

void Buttons_Init(void)
{
	gpio_pin_config_t pin_config = {
		.pinDirection = kGPIO_DigitalInput,
	};

	GPIO_PinInit(BOARD_L1_IN_PORT, BOARD_L1_IN_PIN, &pin_config);
	GPIO_PinInit(BOARD_L2_IN_PORT, BOARD_L2_IN_PIN, &pin_config);
}
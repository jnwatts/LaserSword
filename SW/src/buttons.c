#include "buttons.h"
#include "board.h"

void Buttons_Init(void)
{
	gpio_pin_config_t pin_config = {
		.pinDirection = kGPIO_DigitalInput,
	};

	GPIO_PinInit(BOARD_L1_IN_PORT, BOARD_L1_IN_PIN, &pin_config);
	GPIO_PinInit(BOARD_L2_IN_PORT, BOARD_L2_IN_PIN, &pin_config);
	GPIO_PinInit(BOARD_SW1_PORT, BOARD_SW1_PIN, &pin_config);
}

uint32_t Delay_Button_Value(delay_button_t *delay_button)
{
	bool state = delay_button->read_state();
	if (state) {
		delay_button->counter++;
	} else if (delay_button->counter > 0) {
		uint32_t value = delay_button->counter;
		delay_button->counter = 0;
		return value;
	}

	return 0;
}
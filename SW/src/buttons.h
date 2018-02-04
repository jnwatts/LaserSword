#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

#include <fsl_gpio.h>

#include "board.h"

typedef bool (*read_state_fptr)(void);

typedef struct {
	read_state_fptr read_state;
	uint32_t counter;
} delay_button_t;

void Buttons_Init(void);

uint32_t Delay_Button_Value(delay_button_t *delay_button);

static inline bool ReadL1State(void) { return GPIO_PinRead(BOARD_L1_IN_PORT, BOARD_L1_IN_PIN); }
static inline bool ReadL2State(void) { return GPIO_PinRead(BOARD_L2_IN_PORT, BOARD_L2_IN_PIN); }
static inline bool ReadSW1State(void) { return GPIO_PinRead(BOARD_SW1_PORT, BOARD_SW1_PIN); }

#endif
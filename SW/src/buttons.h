#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

#include <fsl_gpio.h>

#include "board.h"

void Buttons_Init(void);

static inline bool ReadL1State(void) { return GPIO_PinRead(BOARD_L1_IN_PORT, BOARD_L1_IN_PIN); }
static inline bool ReadL2State(void) { return GPIO_PinRead(BOARD_L2_IN_PORT, BOARD_L2_IN_PIN); }

#endif
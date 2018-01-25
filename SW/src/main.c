#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#ifdef DEBUG
//TODO: Trim fat of debug console, else we currently over-shoot flash size by 50%
#include <fsl_debug_console.c>
#define DBG PRINTF
#else
#define DBG(...)
#define DBG(...)
#endif

int main(void)
{
	/* Init board hardware */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	DBG("%s\n", BOARD_NAME);

	while (1) { }
}
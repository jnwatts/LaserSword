/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKE04Z8xxx4
package_id: MKE04Z8VFK4
mcu_data: ksdk2_0
processor_version: 0.0.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '15', peripheral: UART0, signal: TX, pin_signal: PTB1/KBI0_P5/UART0_TX/SPI0_MISO/TCLK2/ADC0_SE5}
  - {pin_num: '16', peripheral: UART0, signal: RX, pin_signal: PTB0/KBI0_P4/UART0_RX/SPI0_PCS0/PWT_IN1/ADC0_SE4}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  PORT_SetPinSelect(kPORT_UART0, kPORT_UART0_RXPTB0_TXPTB1);  /* pin 15,16 is configured as UART0_TX, UART0_RX */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/


#include "system_config.h"
#include "peripheral/ports/plib_ports.h"


void SYS_PORTS_Initialize(void)
{
    /* AN and CN Pins Initialization */
    //PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
    //PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
    //PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
    //PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);
    
    /* PORT A Initialization */
    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  0x0080);
    //PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_A, SYS_PORT_A_ODC);
    PLIB_PORTS_PinModeSelect (PORTS_ID_0, PORTS_ANALOG_PIN_9, PORTS_PIN_MODE_DIGITAL);
}


/*******************************************************************************
 End of File
*/

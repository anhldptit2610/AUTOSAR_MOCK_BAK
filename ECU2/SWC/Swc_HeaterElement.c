#include "Swc_HeaterElement.h"

FUNC(Std_ReturnType, HEATERELEMENT_CODE) HeaterElement(VAR(void, AUTOMATIC))
{
    VAR(Std_ReturnType, AUTOMATIC) ret = E_OK;
    VAR(AUTOSAR_uint8, AUTOMATIC) HeaterControlSignal;
    VAR(HeaterLevel, AUTOMATIC) HeaterLevel;

    Rte_Read_RP_MHControl_HeaterControlSignal(&HeaterControlSignal);
    if (HeaterControlSignal == ON) {
        Rte_Read_RP_MHControl_HeaterLevel(&HeaterLevel);
        Rte_Call_HeaterElement_W_To_IoHwAb_TurnHeaterOn(HeaterLevel);
    } else {
        Rte_Call_HeaterElement_W_To_IoHwAb_TurnHeaterOff();
    }
    return ret;
}
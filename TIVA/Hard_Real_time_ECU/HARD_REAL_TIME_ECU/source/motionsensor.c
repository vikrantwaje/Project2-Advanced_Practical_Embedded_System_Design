/*********************************************************************************
 * @file motionsensor.c
 * @brief Contains motion sensor functions
 * @author Tanmay Chaturvedi & Vikrant Waje
 * @date April 23, 2018
 *
 * *****************************************************************************/
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "motionsensor.h"
//***********************************************************************************
//                                  Global variables
//***********************************************************************************
//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the motion sensor
   PH1 = motion sensor pin
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void motion_sensor_init(void)
{
    GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_1);
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Senses the motion
  @param: None
  @param:None

  @return: Detects motion
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool motion_sensor(void)

{
    uint32_t val = 0;

    val = GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1);
    if(val!=0){
        return 1;
    }
    else
        return 0;
    //UARTprintf("val = %d\n", val);
}

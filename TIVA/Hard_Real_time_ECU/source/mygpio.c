/***************************************************************************************
 * @file mygpio.c
 * @brief This file is to be used for the setting the GPIO of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://www.ti.com/lit/an/spma073/spma073.pdf
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "mygpio.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the GPIO peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void gpio_init(void)
{

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    //
    // Check if the peripheral access is enabled.
     //
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION));


     //Enable the GPIO that are used for I2C Interface Pins
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
     //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);

     //Wait for the Peripheral to be ready for programming
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL) /*|| SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK)*/);

     //
     // Configure Pins for I2C2 Master Interface
     //
     GPIOPinConfigure(GPIO_PL1_I2C2SCL);
     GPIOPinConfigure(GPIO_PL0_I2C2SDA);
     GPIOPinTypeI2C(GPIO_PORTL_BASE, GPIO_PIN_0);
     GPIOPinTypeI2CSCL(GPIO_PORTL_BASE, GPIO_PIN_1);




}

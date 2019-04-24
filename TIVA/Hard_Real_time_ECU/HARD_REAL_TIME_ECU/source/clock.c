/***************************************************************************************
 * @file clock.c
 * @brief This file is to be used for the setting the  clock peripheral of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <clock.h>


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the clock peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void clock_init(void)
{

    // Set the clocking to run at 50 MHz from the PLL.
    sys_clock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                           SYSCTL_OSC_MAIN |
                                           SYSCTL_USE_PLL |
                                           SYSCTL_CFG_VCO_480), CLOCK_FREQ);
   /* sys_clock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                           SYSCTL_OSC_MAIN |
                                           SYSCTL_USE_OSC), 25000000);*/
    //SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_4MHZ |SYSCTL_OSC_MAIN);
}

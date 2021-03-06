/***********************************************************************************
 * @file clock.h
 * @brief Contains program for initialising clock
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_CLOCK_H_
#define INCLUDES_CLOCK_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************
#define CLOCK_FREQ  (25000000 )


//***********************************************************************************
//                              Global variables
//***********************************************************************************
extern uint32_t sys_clock;


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the clock peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void clock_init();





#endif /* INCLUDES_CLOCK_H_ */

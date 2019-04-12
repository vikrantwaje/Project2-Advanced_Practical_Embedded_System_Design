/***************************************************************************************
 * @file mystack.c
 * @brief This file is to be used for the setting the  stack and its handler for the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"mystack.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the stack overflow handler.


 @param: xTaskHandle: TaskHandler of particular task
 @param:pcTaskName: Pointer to task name

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    while(1)
    {
    }
}

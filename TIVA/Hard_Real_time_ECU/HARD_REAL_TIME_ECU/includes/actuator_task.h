/***********************************************************************************
 * @file actuator_task.h
 * @brief Contains callback function for actuator task
 * @author Tanmay C
 * @date April 23, 2019
 *
 *****************************************************************************/

#ifndef INCLUDES_ACTUATOR_TASK_H_
#define INCLUDES_ACTUATOR_TASK_H_
//***********************************************************************************
//                              Include files
//***********************************************************************************
#include"lcd.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************


//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/***********************************************************************************
/*
 @brief:For running actuators based on commands from controller node (BBG)

 @param: None
 @param: None

 @return: None
 **************************************************************************************/

void actuator_task(void *pvParameters);



#endif /* INCLUDES_ACTUATOR_TASK_H_ */
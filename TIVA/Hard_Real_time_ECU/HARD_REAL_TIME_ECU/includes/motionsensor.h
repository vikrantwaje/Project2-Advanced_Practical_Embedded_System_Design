/*********************************************************************************
 * @file motionsensor.h
 * @brief Contains motion sensor functions
 * @author Tanmay C
 * @date April 23, 2018
 *
 * *****************************************************************************/

#ifndef MOTION_SENSOR_H_
#define MOTION_SENSOR_H_
//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include<stdbool.h>
//***********************************************************************************
//                                  Macros
//***********************************************************************************


//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
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
void motion_sensor_init(void);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Senses the motion
  @param: None
  @param:None

  @return: Detects motion
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool motion_sensor(void);


#endif /* MYMOTION_SENSOR_H_ */
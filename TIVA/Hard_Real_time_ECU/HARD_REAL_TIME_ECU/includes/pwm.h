/***********************************************************************************
* @file pwm.h
 * @brief This file is to be used for the setting the PWM of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://nuclearrambo.com/wordpress/generating-pwm-on-tiva-c-connected-launchpad-tm4c1294/
 *
 *****************************************************************************/

#ifndef INCLUDES_PWM_H_
#define INCLUDES_PWM_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/pwm.h"
#include "clock.h"

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
  @brief: Setup the PWM peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void pwm_init();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Set the PWM duty cycle and frequency


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void set_pwm_duty_cycle_freq(uint32_t pwm_freq);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Disable PWM


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void pwm_disable();

#endif /* INCLUDES_PWM_H_ */
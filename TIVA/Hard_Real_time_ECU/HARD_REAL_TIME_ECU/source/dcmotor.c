/***********************************************************************************
 * @file dcmotor.c
 * @brief Contains functions to control speed of motor
 * @author Vikrant Waje
 * @date April 15, 2019
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "dcmotor.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the GPIO pins required for operation of DC motor.

       = EN(PWM OUTPUT)
   PM7 = LEG1
   PM6 = LEG2
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void dcmotor_init(){
    //Will not work since we do not have 3.3V to 5V voltage level converter
/*    int32_t read_val = 0;
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7 | GPIO_PIN_6 );
    GPIOPinWrite(GPIO_PORTM_BASE,GPIO_PIN_7,0x80);  //LEG1 = LOGIC1
    read_val = GPIOPinRead(GPIO_PORTM_BASE, GPIO_PIN_6);
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, read_val & ~(0x40));*/

}

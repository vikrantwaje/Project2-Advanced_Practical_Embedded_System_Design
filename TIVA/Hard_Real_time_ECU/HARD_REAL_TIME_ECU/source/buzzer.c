/***********************************************************************************
 * @file buzzer.c
 * @brief Contains functions to turn buzzer ON/OFF
 * @author Vikrant Waje
 * @date April 11, 2018
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "buzzer.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
bool fadeup;
uint32_t i;
//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Turn the Buzzer ON .


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void buzzer_on()
{
    PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
    PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true); // Enable PWM output channel 4


/*          for(i=0;i<20000;i++){
            if(i<=10000){
             PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, 9999);
            //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 9999);
            //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 9999);


            SysCtlDelay(10);
            }
            else if(i>=10000)
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, 0);
            //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 0);
            //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0);


            SysCtlDelay(10);
          }



        SysCtlDelay(100);*/

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Turn the Buzzer OFF .


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void buzzer_off()
{
      PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
}

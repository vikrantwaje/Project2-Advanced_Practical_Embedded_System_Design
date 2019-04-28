/***************************************************************************************
 * @file pwm.c
 * @brief This file is to be used for the setting the PWM of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://nuclearrambo.com/wordpress/generating-pwm-on-tiva-c-connected-launchpad-tm4c1294/
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "pwm.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the PWM peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void pwm_init(){
        SysCtlPWMClockSet(SYSCTL_PWMDIV_1);         // Enable clock to PWM module
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); // Use PWM module 0
        PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_NO_SYNC);
        PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_NO_SYNC);

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Set the PWM duty cycle and frequency


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void set_pwm_duty_cycle_freq(uint32_t pwm_freq){
            uint32_t pwm_word = 0;
            pwm_word = (1.0/pwm_freq)* /*SysCtlPWMClockGet()*/(sys_clock);

            //For Buzzer
            PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, /*100000*/pwm_word);  // Set PWM frequency
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, PWMGenPeriodGet(PWM0_BASE,PWM_GEN_2)/2/*6*/); // Set Duty cycle
           // PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true); // Enable PWM output channel 4

            //For servo motor
            PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 100000/*pwm_word*/);  // Set PWM frequency
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE,PWM_GEN_2)/2/*6*/); // Set Duty cycle
            PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true); // Enable PWM output channel 5

            //For motor
            PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, /*100000*/pwm_word);  // Set PWM frequency
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, PWMGenPeriodGet(PWM0_BASE,PWM_GEN_3)/2/*6*/); // Set Duty cycle
            PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true); // Enable PWM output channel 5

            PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
            PWMGenEnable(PWM0_BASE, PWM_GEN_3); // Enable PWM module

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Disable PWM


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void pwm_disable(){
    PWMGenDisable(PWM0_BASE, PWM_GEN_2);
}

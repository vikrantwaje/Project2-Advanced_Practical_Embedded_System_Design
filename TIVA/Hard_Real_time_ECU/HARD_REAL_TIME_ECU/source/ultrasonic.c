/***************************************************************************************
 * @file ultrasonic.c
 * @brief This file is to be used for the setting the ultrasonic sensor.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference:https://github.com/LuisAfonso95/TM4C123-Launchpad-Examples/blob/master/srf04/main.c
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "ultrasonic.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
//Stores the pulse length
volatile uint32_t pulse_length;

//Tells the main code if the a pulse is being read at the moment
volatile uint8_t echowait;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: GPIO interrupt for ultrasonic sensor


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void measure_echo(){
  //Clear interrupt flag. Since we only enabled on this is enough
  GPIOIntClear(GPIO_PORTM_BASE, GPIO_PIN_2);

  /*
    If it's a rising edge then set he timer to 0
    It's in periodic mode so it was in some random value
  */
  if ( GPIOPinRead(GPIO_PORTM_BASE, GPIO_PIN_2) == GPIO_PIN_2){
    HWREG(TIMER0_BASE + TIMER_O_TAV) = 0; //Loads value 0 into the timer.
    TimerEnable(TIMER0_BASE,TIMER_A);
    echowait=1;
  }
  /*
    If it's a falling edge that was detected, then get the value of the counter
  */
  else{
    pulse_length = TimerValueGet(TIMER0_BASE,TIMER_A); //record value
    TimerDisable(TIMER0_BASE,TIMER_A);
    echowait=0;
  }


}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send trigger from ultrasonic sensor


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void ultrasonic_send_trigger(){
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_1,0x02);  //Make trigger pin logic 1
    SysCtlDelay(100);                                       //Insert delay of atleast 10us
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_1,0x00);  //Make trigger pin logic 0

}

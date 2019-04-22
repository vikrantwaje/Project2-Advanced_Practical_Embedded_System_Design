/***************************************************************************************
 * @file mytimer.c
 * @brief This file is to be used for the setting the timer of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://www.ti.com/lit/an/spma073/spma073.pdf
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <timer.h>


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t count;
 SemaphoreHandle_t xSemaphore_led;
 SemaphoreHandle_t xSemaphore_temperature;
//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Timer0 Handler


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*void Timer0IntHandler(void)
{
   // UARTprintf("\n%u",xTaskGetTickCount());
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    IntMasterDisable();
    //UARTprintf("\n\rIn ISR");
    if( xSemaphoreGive( xSemaphore_led ) != pdTRUE )
    {
        // We would expect this call to fail because we cannot give
        // a semaphore without first "taking" it!
    }
    count++;
    if(count%24 == 0){        //Check when count value reaches time equivalent to 100 ms
        if( xSemaphoreGive( xSemaphore_temperature ) != pdTRUE )
          {
              // We would expect this call to fail because we cannot give
              // a semaphore without first "taking" it!
          }
    }
    IntMasterEnable();

}*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the timer peripheral in capture mode.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void timer_capture_init(){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);   //Enable clock to timer0 peripheral
   // IntMasterEnable();
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC_UP);    //Enable timer in periodic mode
    //TimerLoadSet(TIMER0_BASE, TIMER_A, CLOCK_FREQ/1000);     //Load the timer with given count after which it will generate an interrupt,right now set as 1ms
    //IntEnable(INT_TIMER0A);                             //Enable Timer0A interrupt
    //TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);    //Enables individual timer interrupt
    TimerEnable(TIMER0_BASE, TIMER_A);                  //Starts timer
}

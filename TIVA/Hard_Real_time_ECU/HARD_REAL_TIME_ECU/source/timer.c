/***************************************************************************************
 * @file timer.c
 * @brief This file is to be used for the setting the timer of the microcontroller.
 * @author Vikrant Waje and Tanmay Chaturvedi
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
 SemaphoreHandle_t xSemaphore_srt;
 SemaphoreHandle_t xSemaphore_hrt;
 uint8_t uart_connection_flag;
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
void Timer1IntHandler(void)
{
   // UARTprintf("\n%u",xTaskGetTickCount());
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
    IntMasterDisable();
    //UARTprintf("\n\rIn ISR");
    if( xSemaphoreGive( xSemaphore_hrt ) != pdTRUE )
    {
        // We would expect this call to fail because we cannot give
        // a semaphore without first "taking" it!
    }
    count++;
    if(count%24 == 0){        //Check when count value reaches time equivalent to 100 ms
        if( xSemaphoreGive( xSemaphore_srt ) != pdTRUE )
          {
              // We would expect this call to fail because we cannot give
              // a semaphore without first "taking" it!
          }
    }
    if(count%100 == 0){        //Check when count value reaches time equivalent to 100 ms
        if( uart_connection_flag == 1 )
          {
              // We would expect this call to fail because we cannot give
              // a semaphore without first "taking" it!
          }
        else if(uart_connection_flag == 0){
            UART_create_packet_and_transmit("|x|",10);
        }
        uart_connection_flag = 0;

    }
    IntMasterEnable();

}
 /*------------------------------------------------------------------------------------------------------------------------------------*/
 /*
   @brief: Setup the timer peripheral to fire periodically


  @param: None
  @param:None

  @return: None
  */
 /*-----------------------------------------------------------------------------------------------------------------------------*/
 void timer_init(){

     SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);   //Enable clock to timer1 peripheral
     IntMasterEnable();
     TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);    //Enable timer in periodic mode
     TimerLoadSet(TIMER1_BASE, TIMER_A, CLOCK_FREQ/500);     //Load the timer with given count after which it will generate an interrupt,right now set as 1ms
     IntEnable(INT_TIMER1A);                             //Enable Timer1A intserrupt
     TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);    //Enables individual timer interrupt
     TimerEnable(TIMER1_BASE, TIMER_A);                  //Starts timer
 }
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

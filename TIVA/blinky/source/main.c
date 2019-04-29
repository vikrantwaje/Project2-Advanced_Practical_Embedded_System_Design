/************************************************************************************
 * @file main.c
 * @brief Contains main function
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 ************************************************************************************/

//***********************************************************************************
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"main.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
xSemaphoreHandle logger_mutex;
TaskHandle_t Alert_taskhandler ;
SemaphoreHandle_t xSemaphore_led;
SemaphoreHandle_t xSemaphore_temperature;
//***********************************************************************************
//                              Function implementation
//***********************************************************************************

int main(void)
{

    xSemaphore_led = xSemaphoreCreateBinary();  //Sempahore for led task
    xSemaphore_temperature = xSemaphoreCreateBinary();  //Semaphore for temperature task
    system_init();  //Initialises peripherals required for system operation
    create_logger_queue();
    logger_mutex = xSemaphoreCreateMutex();   //Create Mutex for logger queue protection


    // Create the logger task.
    //
     if(xTaskCreate(LoggerTask, (const portCHAR *)"LOGGER", 128, NULL, tskIDLE_PRIORITY + PRIORITY_LOGGER_TASK, NULL) != pdTRUE)
     {
     return(1);  //Error checking
     }
//
    // Create the LED task.
    //
     if(xTaskCreate(LedTask, (const portCHAR *)"LED", 128, NULL, tskIDLE_PRIORITY + PRIORITY_LED_TASK, NULL) != pdTRUE)
     {
     return(1);  //Error checking
     }
     // Create the temperature task.
     //
      if(xTaskCreate(TemperatureTask, (const portCHAR *)"TEMPERATURE", 128, NULL, tskIDLE_PRIORITY + PRIORITY_TEMPERATURE_TASK, NULL) != pdTRUE)
      {
      return(1);  //Error checking
      }

      if(xTaskCreate(AlertTask, (const portCHAR *)"ALERT", 128, NULL, tskIDLE_PRIORITY + PRIORITY_ALERT_TASK,  &Alert_taskhandler) != pdTRUE)
      {
      return(1);  //Error checking
      }
      //
    //
    // Start the scheduler.  This should not return.
    //
    vTaskStartScheduler();

    //
    // In case the scheduler returns for some reason, print an error and loop
    // forever.
    //
    delete_logger_queue();
    while (1)
    {
    }
}

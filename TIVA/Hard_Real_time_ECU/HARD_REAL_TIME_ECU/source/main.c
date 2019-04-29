/************************************************************************************
 * @file main.c
 * @brief Contains main function
 * @author Vikrant Waje & Tanmay Chaturvedi
 * @date April 7, 2019
 *
 ************************************************************************************/

//***********************************************************************************
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"main.h"
#include<stdint.h>
//***********************************************************************************
//                                  Global variables
//***********************************************************************************


QueueHandle_t myqueuehandle ;
SemaphoreHandle_t xSemaphore ;
volatile uint32_t pulse_length;




//***********************************************************************************
//                              Function implementation
//***********************************************************************************

void main(void)
{

    double temperature_value ;
    uint32_t test_pulse_length = 0;
    system_init();
    LCD_send_string("LCD INITIALISED");
    bist();
    authenticate();


    BaseType_t  xReturned;
    xSemaphore = xSemaphoreCreateMutex();



    //for Soft Real Time sensing
    xReturned = xTaskCreate(srt_sensor_data_task, (const portCHAR *)"SRT Sensor Acquisition Task", \
                            2000, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("SOFT REAL TIME SENSOR DATA TASK FAILED");
        return SRT_SENSOR_TASK_CREATE_FAILED;
    }

    //for Hard Real Time sensing
    xReturned = xTaskCreate(hrt_sensor_data_task, (const portCHAR *)"HRT Sensor Acquisition Task", \
                            2000, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("HARD REAL TIME SENSOR DATA TASK FAILED");
        return HRT_SENSOR_TASK_CREATE_FAILED;
    }

    //for Data communication via UART
    xReturned = xTaskCreate(data_communication_task, (const portCHAR *)"Data Communication Task", \
                            2000, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("DATA COMMUNICATION TASK FAILED");
        return COMMUNICATION_TASK_CREATE_FAILED;
    }

    //for Actuator
    xReturned = xTaskCreate(actuator_task, (const portCHAR *)"Actuator Task", \
                            200, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("ACTUATOR TASK FAILED");
        return ACTUATOR_TASK_CREATE_FAILED;
    }

    vTaskStartScheduler();
    return PROGRAM_SUCCESS;



}

/***************************************************************************************
 * @file mythreads.c
 * @brief This file is to be used for defining the callback function associated with two threads
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"main.h"
//***********************************************************************************
//                                  Global variables
//***********************************************************************************


uint32_t g_ui32LEDDelay;
xSemaphoreHandle logger_mutex;  //Mutex to protect simultaneous access to Queue
QueueHandle_t xLogger_Queue; //Queue through which messages are passed
log_msg_t logger_message;   //Structure to store logger messages
log_msg_t receive_message;  // Structure to receive messages
TaskHandle_t Alert_taskhandler;
SemaphoreHandle_t xSemaphore_led;
SemaphoreHandle_t xSemaphore_temperature;


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Callback function for Led Task


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LedTask(void *pvParameters)
{
    uint32_t count = 0;

    while (1)
    {

        if (xSemaphoreTake(xSemaphore_led, (TickType_t )portMAX_DELAY) == pdTRUE)
        {

            led_on(D1_LED_PORT, D1_LED_PIN, D1_ON);
            led_on(D2_LED_PORT, D2_LED_PIN, D2_ON);

            vTaskDelay((50));

            led_off(D1_LED_PORT, D1_LED_PIN, OFF);
            led_off(D2_LED_PORT, D2_LED_PIN, OFF);
            vTaskDelay((50));

            strcpy(logger_message.custom_message, "Led Task");
            logger_message.thread_specific_data = count++;
            logger_message.timestamp = xTaskGetTickCount();
            logger_message.id = LED_TASK;

            if (xSemaphoreTake( logger_mutex, ( TickType_t )portMAX_DELAY) == pdTRUE)

            {
                xQueueSend(xLogger_Queue, (void * ) &logger_message,
                           (TickType_t )portMAX_DELAY);
                xSemaphoreGive(logger_mutex);

            }

           // vTaskDelay(pdMS_TO_TICKS(2));

        }
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Callback function for Temperature Task


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void TemperatureTask(void *pvParameters)
{
    i2c_status_t read_status;
    double *temperature_value = NULL;
    temperature_value = malloc(sizeof(double));
    while (1)
    {

        // UARTprintf("\n\nValue = %u%c%u\n", (uint32_t) *temperature_value,'.',float_val);

        if (xSemaphoreTake(xSemaphore_temperature,
                (TickType_t ) portMAX_DELAY) == pdTRUE)
        {

            //i2c_read_two_byte(TEMP_SENSOR_I2C_ADDRESS,TEMPERATURE_REG, temp_data);
            read_status = get_temperature(REQUEST_CELSIUS, temperature_value);
            if (*temperature_value >= 29)
            {
                xTaskNotifyGive(Alert_taskhandler);

            }

            if (read_status != READ_SUCCESS)
            {
                // UARTprintf("\n\nReading from temperature sensor failed!\n");

            }

            strcpy(logger_message.custom_message, "Temp Task");
            logger_message.thread_specific_data = *temperature_value;
            logger_message.timestamp = xTaskGetTickCount();
            logger_message.id = TEMP_TASK;
            if (xSemaphoreTake( logger_mutex, ( TickType_t )portMAX_DELAY ) == pdTRUE)
            {
                xQueueSend(xLogger_Queue, (void * ) &logger_message,
                           (TickType_t )portMAX_DELAY);
                xSemaphoreGive(logger_mutex);

            }
        }

        //vTaskDelay(pdMS_TO_TICKS(500));

        //}
    }

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Callback function for Logger Task


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LoggerTask(void *pvParameters)
{
    uint8_t float_val;

    while (1)
    {
        if (xQueueReceive(xLogger_Queue, &(receive_message),
                (TickType_t ) portMAX_DELAY) == pdTRUE)
        {

            switch (receive_message.id)
            {

            case (ALERT_TASK):
                UARTprintf("\n\n\n\r[%u msec] [ALERT TASK:%s] ",
                           receive_message.timestamp,
                           receive_message.custom_message,
                           (uint32_t) receive_message.thread_specific_data);

                break;
            case (TEMP_TASK):
        float_val = (100 * (receive_message.thread_specific_data))
                            - (100 * (uint32_t) (receive_message.thread_specific_data));
                UARTprintf(
                        "\n\n\n\r[%u msec] [%s][VIKRANT] [Temperature Value = %u.%u Celsius] ",
                        receive_message.timestamp,
                        receive_message.custom_message,
                        (uint32_t) receive_message.thread_specific_data,
                        float_val);
                break;

            case (LED_TASK):
                UARTprintf("\n\n\n\r[%u msec] [%s][VIKRANT] [Toggle count = %u ] ",
                           receive_message.timestamp,
                           receive_message.custom_message,
                           (uint32_t) receive_message.thread_specific_data);
                break;

            default:

            }

        }

    }

}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Callback function for Alert Task
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void AlertTask(void *pvParameters)
{
    while (1)
    {

        ulTaskNotifyTake( pdTRUE, portMAX_DELAY);

        strcpy(logger_message.custom_message, "THRESHOLD_CROSSED");
        logger_message.thread_specific_data = 0;
        logger_message.timestamp = xTaskGetTickCount();
        logger_message.id = ALERT_TASK;
        if (xSemaphoreTake( logger_mutex, ( TickType_t )portMAX_DELAY ) == pdTRUE)
        {
            xQueueSend(xLogger_Queue, (void * ) &logger_message,
                       (TickType_t )portMAX_DELAY);
            xSemaphoreGive(logger_mutex);

        }

    }

}

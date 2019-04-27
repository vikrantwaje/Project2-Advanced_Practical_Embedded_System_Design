/***********************************************************************************
 * @file data_communication_task.c
 * @brief Contains callback function for communication task
 * @author Tanmay C
 * @date April 23, 2019
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "data_communication_task.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
sensor_data_acq_t receive_srt;
char receive_hrt[10];

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************
/*
 @brief: For communicating sensor data to the remote node (TIVA) via UART.

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void data_communication_task(void *pvParameters)
{
    uint8_t uart_val =0;
    while(1){
        xQueueReceive(xhrt_Queue, &(receive_hrt),(TickType_t ) portMAX_DELAY);
        UART_create_packet_and_transmit(&receive_hrt,sizeof(uint8_t)*10);
      //  uart_val = UARTCharGet(UART7_BASE);
        //  UARTCharPut(UART0_BASE, uart_val);
        xQueueReceive(xcommunication_Queue, &(receive_srt),(TickType_t ) portMAX_DELAY);
        UART_create_packet_and_transmit(&receive_srt,sizeof(sensor_data_acq_t));
       /* uart_val = UARTCharGet(UART7_BASE);
          UARTCharPut(UART0_BASE, uart_val);*/


    }

}



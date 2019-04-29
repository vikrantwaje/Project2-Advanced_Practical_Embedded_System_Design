/***********************************************************************************
 * @file actuator_task.c
 * @brief Contains callback function for actuator task
 * @author Tanmay C
 * @date April 23, 2019
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "actuator_task.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************
/*
 @brief:For running actuators based on commands from controller node (BBG)

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void actuator_task(void *pvParameters)
{
    uint8_t receive_data = 0;
    uint8_t last_receive_data =0;
    while(1){
       // LCD_clear();
        xQueueReceive(xactuator_Queue, &(receive_data),(TickType_t ) portMAX_DELAY);

        if(receive_data == 'G' && last_receive_data!=receive_data){
          //  LCD_clear();
            SysCtlDelay(50000);
            //LCD_send_string("Accident!");
            last_receive_data = receive_data;

        }
 /*       else if(receive_data == 'M' && last_receive_data!=receive_data){
            LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("Motion detect");
             last_receive_data = receive_data;


        }*/
        else if(receive_data == 'U' && last_receive_data!=receive_data){
/*            LCD_clear();
            SysCtlDelay(50000);
            LCD_move_cursor(0x00);
            LCD_send_string("Watch Distance");
            last_receive_data = receive_data;
            SysCtlDelay(50000);*/
        }

        else if(receive_data == 'T' && last_receive_data!=receive_data){
   /*         LCD_clear();
             SysCtlDelay(50000);
             LCD_move_cursor(0x40);
             LCD_send_string("Open Window");
             last_receive_data = receive_data;
             xSemaphoreGive( lcd_mutex); //Mutex unlock for LCD*/

             //SysCtlDelay(50000);

        }

        else if(receive_data == 'A' && last_receive_data!=receive_data){
            xSemaphoreTake( lcd_mutex, ( TickType_t )portMAX_DELAY );   //Mutex lock for LCD
            LCD_clear();
            SysCtlDelay(50000);
            //LCD_move_cursor(0x40);
             LCD_send_string("Drunk");
             last_receive_data = receive_data;
             xSemaphoreGive( lcd_mutex); //Mutex unlock for LCD

            // SysCtlDelay(50000);
        }
        else if(receive_data == 'S' && last_receive_data!=receive_data){
                     /*   LCD_clear();
                       SysCtlDelay(50000);
                       LCD_move_cursor(0x54);
                        LCD_send_string("Failure");
                        last_receive_data = receive_data;
                        SysCtlDelay(50000);*/

          }

        else if(receive_data == 'D' && last_receive_data!=receive_data){
            xSemaphoreTake( lcd_mutex, ( TickType_t )portMAX_DELAY );   //Mutex lock for LCD
            LCD_clear();
             SysCtlDelay(50000);
             LCD_move_cursor(0x14);
             LCD_send_string("Degraded");
             last_receive_data = receive_data;
             xSemaphoreGive( lcd_mutex); //Mutex unlock for LCD

             //SysCtlDelay(50000);


        }
/*        else if(receive_data == 'B' && last_receive_data!=receive_data){
             LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("TX BROKEN");
             last_receive_data = receive_data;

        }
        else if(receive_data == 'X' && last_receive_data!=receive_data){
             LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("RX BROKEN");
             last_receive_data = receive_data;

        }*/

 /*       else{
            LCD_clear();
            SysCtlDelay(50000);
            //LCD_send_string("Engine activated");
        }*/
        receive_data = 0;

    }

}



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
            LCD_clear();
            SysCtlDelay(50000);
            LCD_send_string("Accident!");
            last_receive_data = receive_data;

        }
        else if(receive_data == 'M' && last_receive_data!=receive_data){
            LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("Motion detect");
             last_receive_data = receive_data;


        }
        else if(receive_data == 'U' && last_receive_data!=receive_data){
            LCD_clear();
            SysCtlDelay(50000);
            LCD_send_string("Watch Distance");
            last_receive_data = receive_data;

        }

        else if(receive_data == 'T' && last_receive_data!=receive_data){
             LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("Open Window");
             last_receive_data = receive_data;

        }
        else{
         /*   LCD_clear();
            SysCtlDelay(50000);*/
            //LCD_send_string("Engine activated");
        }
        receive_data = 0;

    }

}



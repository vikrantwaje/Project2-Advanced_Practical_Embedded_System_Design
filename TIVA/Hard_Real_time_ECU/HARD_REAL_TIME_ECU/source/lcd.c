/**
 * @file lcd.c
 * @brief This file is to be used for the initialisation and operation of LCD.
 * @author Vikrant Waje
 * @date November 24, 2018
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************
#include"lcd.h"


//***********************************************************************************
// Global variables
//***********************************************************************************


//***********************************************************************************
// Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the GPIO pins of MSP432 to act as RS,RW and EN of LCD.

   PK4 = RS
   PK5 = RW
   PK6 = EN
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_setup(){
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6);
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD delay.


 @param: time: delay
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_delay(uint32_t time){
    uint32_t i=0;
    for(i=0;i<time;i++);
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD initialisation routine.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_init(){
    LCD_delay(FIFTEEN_MS);  //15 ms delay
    SysCtlDelay(500);
    LCD_send_cmd(0x30); //Unlock command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x30); //Unlock command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x30); //Unlock command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x38); //Function set command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x08); // Display OFF command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x0D); // Display ON command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x06); // Entry mode set command
    SysCtlDelay(500);
    //LCD_delay(FIFTEEN_MS);  //15 ms delay
    LCD_send_cmd(0x01); // CLear screen and come to home position command
    //LCD_delay(FIFTY_MS); //50 ms delay
    SysCtlDelay(500);

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send command.


 @param: cmd: Command that is to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_cmd(uint8_t cmd){
    int32_t read_val = 0;

    shift_reg_send_data(cmd);

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_4);    //RS = 0
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_4, read_val & ~0x10);
   // P4->OUT &=~(RS); //RS =0

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_5);    //RW = 0
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_5, read_val & ~0x20);
    //P4->OUT &=~(RW); //RW =0

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_6);    //EN = 1
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, read_val | 0x40);
   // P4->OUT |= (EN); //EN =1
    LCD_delay(FIFTY_MS); //50 ms delay

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_6);    //EN = 0
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, read_val & ~0x40);
    //P4->OUT &=~(EN); //EN =0
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send data.


 @param: data: Data that is to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_data(uint8_t data){
    int32_t read_val = 0;
    shift_reg_send_data(data);
    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_4);    //RS = 1
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_4, read_val | 0x10);

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_5);    //RW = 0
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_5, read_val & ~0x20);

    // P4->OUT |=(RS); //RS =1
    //P4->OUT &=~(RW); //RW =0

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_6);    //EN = 1
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, read_val | 0x40);
   // P4->OUT |= (EN); //EN =1
    SysCtlDelay(500);
    //LCD_delay(FIFTY_MS); //50 ms delay

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_6);    //EN = 0
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, read_val & ~0x40);
    //P4->OUT &=~(EN); //EN =0
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send string.


 @param: data: string that is to be printed
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_string(uint8_t *src){
    uint8_t i = 0;
    //LCD_delay(FIFTY_MS); //50 ms delay
    SysCtlDelay(500);
    while(*(src+i) != '\0'){
        SysCtlDelay(500);
        //LCD_delay(FIFTY_MS); //50 ms delay

        LCD_send_data(*(src + i));

        i++;
    }
        SysCtlDelay(500);
    //LCD_delay(FIFTY_MS); //50 ms delay

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD move cursor.


 @param: pos: Position to which cursor is to be moved
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_move_cursor(uint8_t address){
    if((address>=0x00 && address<=0x1f)||(address>=0x40 && address<=0x5f)){      //If address between 00 and 67, only then accept, otherwise throw error
        LCD_send_cmd((0x80) | (address));   //DB7 = 1 in set DDRAM address command mode

    }
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD clear function.


 @param: Clears the LCD display and brings cursor back to home position
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_clear(){
    LCD_send_cmd(0x01);
}

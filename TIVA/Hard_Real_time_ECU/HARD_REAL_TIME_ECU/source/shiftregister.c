/**
 * @file shiftregister.c
 * @brief This file is to be used for the initialisation and operation of shift register 74HC595.
 * @author Vikrant Waje
 * @date April 13, 2019
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************
#include"shiftregister.h"


//***********************************************************************************
// Global variables
//***********************************************************************************


//***********************************************************************************
// Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the GPIO pins of MSP432 to act as SCLK,RCLK and SERDATA of 74HC595.

   PK0 = SCLK
   PK1 = SERDATA
   PK2 = RCLK
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void shift_reg_setup(){
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2/*|GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6*/);

    //P2->DIR |=(BIT4 | BIT6 |BIT7);

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Introduce delay.

    Create a delay
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void shift_reg_delay(){
    uint16_t i=0;
    for(i=0;i<25;i++);   //Wait for certain time period to introduce delay
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Convert parallel data into serial.

   Convert 8 bit data into stream of 1 bit
   PK1 is the serial data pin
 @param: data_byte: data to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void parallel_to_serial(uint8_t data_byte){
    uint8_t i=0;
    int32_t read_val = 0;
    for(i=0;i<8;i++){

        if(data_byte & (1<<i)){
            read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, read_val | 0x02);
            //P2->OUT |= BIT6;
            shift_reg_sclk();
        }
        else{
            read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, read_val & ~(0x02));
            //P2->OUT &= ~BIT6;
            shift_reg_sclk();
        }
    }
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Serial clock.

   Generate a clock signal for shift register
   PK0 is the serial clock pin
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void shift_reg_sclk(){
    int32_t read_val = 0;

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, read_val | 0x01);
    //P2->OUT |=BIT4;  //Make serial clock logic high
   // shift_reg_delay();

    read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, read_val & ~(0x01)); //Make serial clock low
    //P2->OUT &=~BIT4;
   // shift_reg_delay();
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: R clock.

   Generate a clock signal for latch/strobe
   P2.7 is the serial clock pin
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void shift_reg_rclk(){

    int32_t read_val = 0;

        read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_2);    //Make rclk logic high
        GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, read_val | 0x04);
    //P2->OUT |=BIT7; //Make rclk logic high
    //shift_reg_delay();
        read_val = GPIOPinRead(GPIO_PORTK_BASE, GPIO_PIN_2);
        GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, read_val & ~(0x04)); //Make rclk logic low
   // P2->OUT &=~BIT7; //Make rclk logic low
    //shift_reg_delay();

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send data to 74HC595.


 @param: data_byte: data to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void shift_reg_send_data(uint8_t data_byte){
    parallel_to_serial(data_byte);
    shift_reg_rclk();
}

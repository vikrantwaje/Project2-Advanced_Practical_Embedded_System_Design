/**
 * @file lcd.h
 * @brief Header file for lcd driver.
 * @author Vikrant Waje
 * @date April 13, 2019
 *
 */
#ifndef SRC_LCD_H_
#define SRC_LCD_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include "shiftregister.h"
#include "synchronization.h"

//***********************************************************************************
// Macros
//***********************************************************************************
#define RS (BIT4)
#define RW (BIT5)
#define EN (BIT7)
#define FIFTEEN_MS (1000)
#define FIFTY_MS   (16000)
//***********************************************************************************
// Global variables
//***********************************************************************************


//***********************************************************************************
// Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the GPIO pins of TM4C1294XL to act as RS,RW and EN of LCD.

   PK4 = RS
   PK5 = RW
   P4.7 = EN
 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_setup();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD delay.


 @param: time: delay
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_delay(uint32_t time);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD initialisation routine.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_init();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send command.


 @param: cmd: Command that is to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_cmd(uint8_t cmd);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send data.


 @param: data: Data that is to be sent
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_data(uint8_t data);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD send string.


 @param: src: String that is to be printed
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_send_string(uint8_t *src);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: LCD move cursor.


 @param: pos: Position to which cursor is to be moved
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void LCD_move_cursor(uint8_t address);

#endif /* SRC_LCD_H_ */

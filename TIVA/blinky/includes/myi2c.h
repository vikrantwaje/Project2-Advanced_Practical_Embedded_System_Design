/***********************************************************************************
 * @file myi2c.h
 * @brief Contains initialization and data transfer routine for I2C module
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_MYI2C_H_
#define INCLUDES_MYI2C_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_i2c.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************

#define I2C_WRITE (false)
#define I2C_READ  (true)
typedef enum{READ_SUCCESS, WRITE_SUCCESS, READ_FAILURE, WRITE_FAILURE}i2c_status_t;

//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the I2C module.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void i2c_init();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Read from I2C.

 @param: slave address: Address of sensor from which data is to be read
 @param: reg address: Address of register from which data is to be read
 @param: data: Pointer to data in which data is to be stored

 @return: i2c_status_t: Status of I2C operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
i2c_status_t i2c_read_two_byte(uint8_t slave_addr,uint8_t reg_addr, uint8_t *data);


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Write to I2C.


 @param: reg address: Address to which data is to be written
 @param: data: data to be written

 @return: i2c_status_t: Status of I2C operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
i2c_status_t i2c_write_two_byte(uint8_t slave_addr,uint8_t reg_addr, uint16_t data);
#endif /* INCLUDES_MYI2C_H_ */

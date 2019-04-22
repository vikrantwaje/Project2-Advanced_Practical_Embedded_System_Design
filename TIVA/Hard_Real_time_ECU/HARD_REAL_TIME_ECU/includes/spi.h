/***********************************************************************************
 * @file spi.h
 * @brief Contains function for SPI initialisation and read, write functions
 * @author Vikrant Waje
 * @date April 11, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"
#include "inc/hw_ssi.h"
#include "driverlib/ssi.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "clock.h"
#include "gpio.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************


//***********************************************************************************
//                              Global variables
//***********************************************************************************
typedef enum{
    SPI_WRITE_SUCCESS, SPI_READ_SUCCESS, SPI_WRITE_FAILURE, SPI_READ_FAILURE
}spi_status_t;

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the SPI peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void spi_init();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Write to SPI register


 @param: reg_addr: Register to which data is to be written
 @param: data: Data that is to be written to the register

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_write(uint8_t reg_addr, uint8_t data);


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Write multiple bytes to SPI register


 @param: reg_addr: Register to which data is to be written
 @param: data: Data that is to be written to the register
 @param: length: length of data

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_write_multibyte(uint8_t reg_addr, uint8_t* data,uint8_t length);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Read from SPI register


 @param: reg_addr: Register from which data is to be read
 @param: data: Pointer variable in which data that is read is to be stored

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_read(uint8_t reg_addr, uint32_t *data);




#endif /* INCLUDES_SPI_H_ */

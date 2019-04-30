/***************************************************************************************
 * @file spi.c
 * @brief This file is to be used for the setting the  SPI peripheral of the microcontroller.
 * @author Vikrant Waje and Tanmay Chaturvedi
 * @date April 7, 2019
 * @Reference: https://gist.github.com/terd-ferguson/cb46042bc77b054697aa847b95c250cc
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "spi.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the SPI peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void spi_init(void)
{
    // Enable peripheral for SSI/SPI.
   // SSIDisable(SSI2_BASE);
    SSIConfigSetExpClk(SSI0_BASE, sys_clock, SSI_FRF_MOTO_MODE_3, SSI_MODE_MASTER, 1000000, 8);
    SSIEnable(SSI0_BASE);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Write to SPI register


 @param: reg_addr: Register to which data is to be written
 @param: data: Data that is to be written to the register

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_write(uint8_t reg_addr, uint8_t data){

    uint32_t temp = 0;
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3);   //Make CS high
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,0x00); //Make CS low
    SSIDataPut(SSI0_BASE,reg_addr ); //Send register address
   while(SSIBusy(SSI0_BASE));      //Wait until all data is sent
    SSIDataGet(SSI0_BASE, &temp);
//    UARTprintf("\n\rgfg=%x",temp);
    //while(SSIBusy(SSI0_BASE));      //Wait until register address is sent

    SSIDataPut(SSI0_BASE,data);       //Send data
   while(SSIBusy(SSI0_BASE));      //Wait until all data is sent
    SSIDataGet(SSI0_BASE, &temp);



   // while(SSIBusy(SSI0_BASE));      //Wait until all data is sent
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3);   //Make CS high
    return SPI_WRITE_SUCCESS;

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Write multiple bytes to SPI register


 @param: reg_addr: Register to which data is to be written
 @param: data: Data that is to be written to the register
 @param: length: length of data

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_write_multibyte(uint8_t reg_addr, uint8_t* data,uint8_t length){

    uint8_t i = 0;
    uint32_t temp = 0;
    //while(SSIDataGetNonBlocking(SSI0_BASE, &temp));
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,0x00); //Make CS low
    SSIDataPut(SSI0_BASE,reg_addr);
    while(SSIBusy(SSI0_BASE));      //Wait until all data is sent
     SSIDataGet(SSI0_BASE, &temp);
    for(i=0;i<length;i++){
    SSIDataPut(SSI0_BASE, *(data + i));
    while(SSIBusy(SSI0_BASE));
    SSIDataGet(SSI0_BASE, &temp);
    }
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3); //MAKE PIN HIGH
    return SPI_WRITE_SUCCESS;

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Read from SPI register


 @param: reg_addr: Register from which data is to be read
 @param: data: Pointer variable in which data that is read is to be stored

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_read(uint8_t reg_addr, uint32_t *data){

    uint32_t temp =0;
//    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3);
   // while(SSIDataGetNonBlocking(SSI0_BASE, &temp));
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,0x00); //Make CS low
    SSIDataPut(SSI0_BASE, ((reg_addr)|0x80) );
    while(SSIBusy(SSI0_BASE));
    SSIDataGet(SSI0_BASE, data);

    SSIDataPut(SSI0_BASE, 0xff);
    while(SSIBusy(SSI0_BASE));
    SSIDataGet(SSI0_BASE, data);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3); //MAKE PIN HIGH
    return SPI_READ_SUCCESS;

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Read multiple bytes from SPI register


 @param: reg_addr: Register from which data is to be read
 @param: data: Pointer variable in which data that is read is to be stored

 @return: spi_status_t: Indicates the status of SPI operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
spi_status_t spi_read_multibyte(uint8_t reg_addr, uint32_t *data,uint8_t length){

    uint32_t temp = 0;
    uint8_t i =0;
    //while(SSIDataGetNonBlocking(SSI0_BASE, &temp));
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,0x00); //Make CS low
    SSIDataPut(SSI0_BASE, ((reg_addr)|0x80));
    while(SSIBusy(SSI0_BASE));
    SSIDataGet(SSI0_BASE, data+i);
    for (i = 0; i < length; i++)
    {
        SSIDataPut(SSI0_BASE, 0xff);
        while (SSIBusy(SSI0_BASE));
        SSIDataGet(SSI0_BASE, data+i);



    }
/*
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3); //MAKE PIN HIGH


    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,0x00); //Make CS low
    SSIDataPut(SSI0_BASE, ((reg_addr +1)|0x80));
    while(SSIBusy(SSI0_BASE));
    SSIDataGet(SSI0_BASE, data+i +1);
    //for (i = 0; i < length; i++)
   // {
        SSIDataPut(SSI0_BASE, 0xff);
        while (SSIBusy(SSI0_BASE));
        SSIDataGet(SSI0_BASE, data+i +1);



    //}
     *
     */
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3,GPIO_PIN_3); //MAKE PIN HIGH


    return SPI_READ_SUCCESS;

}

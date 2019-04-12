/***************************************************************************************
 * @file myi2c.c
 * @brief This file is to be used for initialization and data transfer function for I2C module.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://www.ti.com/lit/an/spma073/spma073.pdf
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "myi2c.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Setup the I2C peripheral.
 @param: None
 @param:None
 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void i2c_init(void)
{

    //
    // Stop the Clock, Reset and Enable I2C Module
    // in Master Function
    //
    SysCtlPeripheralDisable(SYSCTL_PERIPH_I2C2);
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C2);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);
    //
    // Wait for the Peripheral to be ready for programming
    //
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C2));
    //
    // Initialize and Configure the Master Module
    //
    I2CMasterInitExpClk(I2C2_BASE, sys_clock, false);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read from I2C.
 @param: reg address: Address from which data is to be read
 @param: data: Pointer to data in which data is to be stored
 @return: i2c_status_t: Status of I2C operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
i2c_status_t i2c_read_two_byte(uint8_t slave_addr,uint8_t reg_addr, uint8_t *data)
{
    //Set the slave address and indicate write operation for transferring the register address
    I2CMasterSlaveAddrSet(I2C2_BASE, slave_addr, I2C_WRITE);
    // Send the register address
    I2CMasterDataPut(I2C2_BASE, reg_addr);
    //Indicate start condition
    I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_START);
    MAP_SysCtlDelay(10000);
    while(I2CMasterBusy(I2C2_BASE));
    //Set the slave address and generate repeated start condition for reading from the bus
    I2CMasterSlaveAddrSet(I2C2_BASE, slave_addr, I2C_READ);
    I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
    MAP_SysCtlDelay(300);
    while (I2CMasterBusy(I2C2_BASE));
    //Get first byte from sensor
    *(data + 1) = I2CMasterDataGet(I2C2_BASE);
    I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
    MAP_SysCtlDelay(1000);
    while (I2CMasterBusy(I2C2_BASE));
    //Get second byte from sensor
    *(data + 0) = I2CMasterDataGet(I2C2_BASE);

    return READ_SUCCESS;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Write to I2C.
 @param: reg address: Address to which data is to be written
 @param: data: data to be written
 @return: i2c_status_t: Status of I2C operation
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
i2c_status_t i2c_write_two_byte(uint8_t slave_addr,uint8_t reg_addr, uint16_t data)
{
    //Set the slave address and indicate write operation for transferring the register address
    I2CMasterSlaveAddrSet(I2C2_BASE, slave_addr, I2C_WRITE);
    // Send the register address
    I2CMasterDataPut(I2C2_BASE, reg_addr);
    //Indicate start condition
    I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_START);
    MAP_SysCtlDelay(10000);
    while(I2CMasterBusy(I2C2_BASE));


    //Write first byte from sensor
    I2CMasterDataPut(I2C2_BASE, (uint8_t)(data >>8));
    MAP_SysCtlDelay(300);
    while (I2CMasterBusy(I2C2_BASE));

    //Write second byte from sensor
    I2CMasterDataPut(I2C2_BASE, (uint8_t)(data));
    MAP_SysCtlDelay(1000);
    while (I2CMasterBusy(I2C2_BASE));

    I2CMasterControl(I2C6_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
    MAP_SysCtlDelay(1000);
    while (I2CMasterBusy(I2C2_BASE));

    return WRITE_SUCCESS;
}

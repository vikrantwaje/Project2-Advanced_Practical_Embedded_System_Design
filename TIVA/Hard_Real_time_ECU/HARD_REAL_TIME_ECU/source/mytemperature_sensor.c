/***********************************************************************************
 * @file mytemperature_sensor.c
 * @brief Contains temp_data transfer function for tempearture sensor
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "mytemperature_sensor.h"
#include<stdlib.h>
#include<stdint.h>
//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************

/***********************************************************************************************
 * @brief Get temperature
 *
 * Read the value from temperature register
 *
 * @param NULL
 * @return double: Value of temperature
 *********************************************************************************************/

i2c_status_t get_temperature(request_cmd_t request, double *temperature_value)
{

    //double result = 0;
    double multiplier = 0.0625;
    int32_t digitalTemp = 0;

    i2c_status_t status = READ_SUCCESS;
    uint8_t temp_data[2];

    if (temp_data == NULL)
    {
        return READ_FAILURE;
    }

    status = i2c_read_two_byte(TEMP_SENSOR_I2C_ADDRESS, TEMPERATURE_REG, temp_data);

    if (status != READ_SUCCESS)
    {
        //free(temp_data);
        return READ_FAILURE;
    }

    // Bit 0 of second byte will always be 0 in 12-bit readings and 1 in 13-bit
    if (*(temp_data + 0) & 0x01)    // 13 bit mode
    {
        // Combine bytes to create a signed int
        digitalTemp = (*(temp_data + 1) << 5) | (*(temp_data + 0) >> 3);
        // Temperature temp_data can be + or -, if it should be negative,
        // convert 13 bit to 16 bit and use the 2s compliment.
        if (digitalTemp > 0xFFF)
        {
            digitalTemp |= 0xE000;
        }
    }
    else    // 12 bit mode
    {
        // Combine bytes to create a signed int
        digitalTemp = (*(temp_data + 1) << 4) | (*(temp_data + 0) >> 4);
        // Temperature temp_data can be + or -, if it should be negative,
        // convert 12 bit to 16 bit and use the 2s compliment.
        if (digitalTemp > 0x7FF)
        {
            digitalTemp |= 0xF000;
        }
    }
    // Convert digital reading to analog temperature (1-bit is equal to 0.0625 C)

    //free(temp_data);

    if (request == REQUEST_KELVIN)
    {
        *temperature_value = (digitalTemp * multiplier + 273.15);
    }
    else if (request == REQUEST_FAHRENHEIT)
    {
        *temperature_value = ((digitalTemp * multiplier * 9.0 / 5.0) + 32.0);
    }
    else
        *temperature_value = (digitalTemp * multiplier);

    return READ_SUCCESS;
}


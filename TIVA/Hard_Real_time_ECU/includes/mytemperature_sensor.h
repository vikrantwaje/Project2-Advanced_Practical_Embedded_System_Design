/***********************************************************************************
 * @file mytemperature_sensor.h
 * @brief Contains data transfer function for tempearture sensor
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_MYTEMPERATURE_SENSOR_H_
#define INCLUDES_MYTEMPERATURE_SENSOR_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include "myi2c.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************
#define TEMP_SENSOR_I2C_ADDRESS (0x48)
#define TEMPERATURE_REG     (0x00)
#define CONFIGURATION_REG    (0x01)
#define TLOW_REG        (0x02)
#define THIGH_REG       (0x03)

#define CONVERSION_RATE_0_25    ((0x00))
#define CONVERSION_RATE_1   ((0x01))
#define CONVERSION_RATE_4   ((0x02))
#define CONVERSION_RATE_8   ((0x03))
#define CONVERSION_RATE_MASK    (0x03)
#define SHUTDOWN_ON     ((0x01))
#define SHUTDOWN_OFF        ((0x00))

#define EM_ON           ((0x01))
#define EM_OFF          ((0x00))
#define EM_MASK         (0x01)


#define FAULT_1         ((0x00))
#define FAULT_2         ((0x01))
#define FAULT_3         ((0x02))
#define FAULT_4         ((0x03))
#define FAULT_MASK      (0x03)

#define RESOLUTION_MASK         (0x03)
#define SENSOR_RESOLUTION_12_BIT    (0x03)

typedef enum{
    REQUEST_CELSIUS, REQUEST_KELVIN, REQUEST_FAHRENHEIT
}request_cmd_t;


//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/***********************************************************************************************
 * @brief Get temperature
 *
 * Read the value from temperature register
 *
 * @param NULL
 * @return double: Value of temperature
 *********************************************************************************************/

i2c_status_t get_temperature(request_cmd_t request,double *temperature_value);
#endif /* INCLUDES_MYTEMPERATURE_SENSOR_H_ */

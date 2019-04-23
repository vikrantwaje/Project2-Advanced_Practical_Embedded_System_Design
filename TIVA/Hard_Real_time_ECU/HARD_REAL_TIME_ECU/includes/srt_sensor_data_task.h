/*
 * str_sensor_data_task.h
 *
 *  Created on: 22 Apr 2019
 *      Author: Tanmay Chaturvedi & Vikrant Waje
 */

#ifndef INCLUDES_SRT_SENSOR_DATA_TASK_H_
#define INCLUDES_SRT_SENSOR_DATA_TASK_H_

/*
 @brief: Soft real-time sensor data communication task

 @param: None

 @return: None
 */
void srt_sensor_data_task(void *pvParameters);


/*
 @brief: Hard real-time sensor data communication task
        for detecting accident condition using gyroscope
 @param: None

 @return: None
 */
void hrt_sensor_data_task(void *pvParameters);



#endif /* INCLUDES_SRT_SENSOR_DATA_TASK_H_ */

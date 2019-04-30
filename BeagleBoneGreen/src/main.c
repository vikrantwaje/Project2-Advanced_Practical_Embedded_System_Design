/*********************************************************************************************
 *                      FILENAME: main.c
 * *****************************************************************************************/
/*
 * @Title: main.c

 * @Author: Vikrant Waje and Tanmay Chaturvedi
 * @Date: 27 April 2019
 * @Tools: vim,gcc
 */

/*********************************************************************************
 *                        HEADER FILE SECTION
 * **********************************************************************************/
#include"main.h"

/*********************************************************************************
 *                        GLOBAL VARIABLES SECTION
 * **********************************************************************************/
mqd_t mqdes1;	
FILE *fptr;
typedef struct{
	uint8_t sensor_data;
	uint8_t log_level;
	uint8_t source_string[70];
}log_t;

/*********************************************************************************
 *                        FUNCTION DEFINITION SECTION
 * **********************************************************************************/
void *logger_thread_callback(void *arg){
	int status = 0;
	log_t receive_buff;
	while(1){
		status = mq_receive(mqdes1,&receive_buff,sizeof(log_t),NULL); //receive routine
		/*if(strcmp(receive_buff.source_string,"Alcohol")==0){
		  if(receive_buff.sensor_data == 0){
		  strcpy(receive_buff.source_string,"ALCOHOL SENSOR REMOVED.EXPECT DEGRADED PERFORMANCE");
		  }

		  }*/
		/*	if(strcmp(receive_buff.source_string,"Ultrasonic")<100){
			if(receive_buff.sensor_data == 0){
			strcpy(receive_buff.source_string,"ULTRASONIC SENSOR REMOVED.SHUTTING DOWN THE SYSTEM");
			}

			}*/
		log_value(fptr,receive_buff.sensor_data,receive_buff.log_level,receive_buff.source_string);
	}
}
void *statemachine_thread_callback(void *arg){
	char *ptr = malloc(sizeof(char) * 40);
	char *tempptr = malloc(sizeof(char) * 40);
	char output[6];
	uint16_t count = 0;
	uint32_t previous_value;
	char temp_buffer[2];
	char adc_buffer[2];
	int temperature = 0;
	int alcohol =0;
	char ultrasonic_buffer[5];
	int ultrasonic = 0;
	char gyro_buffer[1];
	char motion_buffer[1];
	uint16_t i =0;
	int status = 0;
	log_t log_data;
	FILE *fptr = NULL;
	while(1)
	{
		/*if(strcmp(argv[1],"D")==0){
		  read_from_uart(ptr);

		  printf("%s",ptr);
		  }*/
		//else if(strcmp(argv[1],"N")==0){
		//read_from_uart(ptr);

		do{

			read_from_uart(ptr);	//Read one byte from UART
			//Now check whether byte that is read is '|' or not. In short, we need to wait until '|' arrives on UART which indicates start or end of packet
			if(*(ptr + 0)!='|'){
				//		printf("\n\rNot synchronised");
				//	sleep(1.3);
			}

		}while(*(ptr + 0)!='|');	//Wait until the delimiting character arrives

		//Once we get '|', it is necessary to determine whether '|' indicates start or end of packet. To determine that we fetch the next byte after '|'
		read_from_uart(ptr);

		//If the next byte after '|' is a letter, then it indicates start of packet
		switch(*(ptr )){

			case 'g':
				read_from_uart(&gyro_buffer[0]);
				if(gyro_buffer[0]=='1') 
					output[0] ='G';
				else
					output[0]='g';
				printf("\n\rGyro =%c",output[0]);
				log_data.sensor_data = output[0];
				log_data.log_level = 1;
				strcpy(log_data.source_string,"Gyroscope");	
				status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine

				if(status == -1){
					perror("Send unsuccessfull 1");
				} 	
				//	log_value(fptr,output[0],1,"GYROSCOPE");
				break;
			case 'a':
				read_from_uart(&adc_buffer[0]);
				read_from_uart(&adc_buffer[1]);
				read_from_uart(&adc_buffer[2]);
				read_from_uart(&adc_buffer[3]);
				read_from_uart(&adc_buffer[4]);
				alcohol=atoi(adc_buffer);
				if(alcohol == 0){
					output[0]= 'D';
					strcpy(log_data.source_string,"ALCOHOL SENSOR REMOVED.EXPECT DEGRADED PERFORMANCE");

				}
				else if(alcohol > 20){ 
					output[0] ='A';
					strcpy(log_data.source_string,"Alcohol");	
				}
				else{
					output[0]='a';
					strcpy(log_data.source_string,"Alcohol");	
				}
				printf("\n\rAlcohol =%d",alcohol);
				log_data.sensor_data = alcohol;
				log_data.log_level = 2;
				status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine
				if(status == -1){
					perror("Send unsuccessfull 1");
				} 

				//	log_value(fptr,alcohol,5,"ALCOHOL");
				break;
			case 'x':
				output[0]='X';
				log_data.sensor_data = 0;
				log_data.log_level = 6;

				strcpy(log_data.source_string,"TIVA UART RX LINK BROKEN");	

				status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine
				if(status == -1){
					perror("Send unsuccessfull 1");
				} 

				printf("\n\rReceive link of TIVA broken");

				//	log_value(fptr,alcohol,5,"ALCOHOL");
				break;

				/*case 'b':
				  output[0]='B';
				  printf("\n\rTransmit link of TIVA broken");
				  log_data.sensor_data = 0;
				  log_data.log_level = 6;
				  strcpy(log_data.source_string,"TIVA UART TX LINK BROKEN");	
				  status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine
				  if(status == -1){
				  perror("Send unsuccessfull 1");
				  } 

				//	log_value(fptr,alcohol,5,"ALCOHOL");
				break;*/



			case 't':
				read_from_uart(&temp_buffer[0]);
				read_from_uart(&temp_buffer[1]);
				temperature=atoi(temp_buffer);
				if(temperature>=28)
					output[0] ='T';
				else
					output[0]='h';
				log_data.sensor_data = temperature;
				log_data.log_level = 3;
				strcpy(log_data.source_string,"Temperature");	
				status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine
				if(status == -1){
					perror("Send unsuccessfull 1");
				} 
			
				printf("\n\rTemperature=%d",temperature);

				//	log_value(fptr,temperature,2,"TEMPERATURE");
				break;

			case 'u':
				read_from_uart(&ultrasonic_buffer[0]);
				read_from_uart(&ultrasonic_buffer[1]);
				read_from_uart(&ultrasonic_buffer[2]);
				read_from_uart(&ultrasonic_buffer[3]);
				read_from_uart(&ultrasonic_buffer[4]);
				ultrasonic=atoi(ultrasonic_buffer);
				if(ultrasonic  == previous_value ){
					count++;
					if(count == 400){
						output[0]='S';
						count =0;
						strcpy(log_data.source_string,"ULTRASONIC SENSOR REMOVED.SHUTTING DOWN THE SYSTEM");	
					}
					strcpy(log_data.source_string,"CHECK ULTRASONIC SENSOR. ABOUT TO FAIL");	
	
				}
				else if( ultrasonic>135 && ultrasonic<8000){
					output[0] ='U';

					strcpy(log_data.source_string,"Ultrasonic");	
				}
				else{
					output[0] = 'u';
					strcpy(log_data.source_string,"Ultrasonic");	

				}			
				previous_value = ultrasonic;
				//strcpy(log_data.source_string,"Ultrasonic");	

				log_data.sensor_data = ultrasonic;
				log_data.log_level = 4;
				status = mq_send(mqdes1,&log_data,sizeof(log_t),0);	//send routine
				if(status == -1){
					perror("Send unsuccessfull 1");
				} 

			
				printf("\n\rultrasonic =%d",ultrasonic);


				//	log_value(fptr,ultrasonic,3,"ULTRASONIC");
				break;

			default:
				memset(output,0,6);
		}
		output[1]='\n';
		output[2]='\r';
		write_to_uart(output);
		//}

	}


}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: Main function responsible for calling application code.
   @param:None

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
// Main function
void main(int argc, char *argv[])
{
	pthread_t logger, statemachine;
	int status =0;
	uint8_t authenticate = 0;
	uint8_t bist = 0;
	uint8_t auth_buffer[2];
	int ret_val = uart_init();

	printf("ret_val for uart_init = %d", ret_val);

	ret_val = termios_init();
	printf("ret_val for terminos_init = %d", ret_val);
	create_heartbeat_timer();

	read_from_uart(&bist);
	if(bist == '1'){
	log_value(fptr,0,0,"BIST NOT SUCCESSFULL");
	}
	else{
		log_value(fptr,0,0,"BIST SUCCESSFULL");
	}

	do{
		read_from_uart(&authenticate);
		if(authenticate == '1'){
			auth_buffer[0]='1';
			printf("%d",1);
			write_to_uart(&auth_buffer[0]);

		}
		else if(authenticate=='0'){
			auth_buffer[0]='0';
			printf("%d",0);
			log_value(fptr,0,0,"INTRUDER ALERT!!");
			write_to_uart(&auth_buffer[0]);
		}
	}while(authenticate!='1');
	log_value(fptr,0,0,"PASSWORD CORRECT,STARTING ENGINE");

	//Attribute for queue
	struct mq_attr attr1; 
	attr1.mq_maxmsg = 10;
	attr1.mq_msgsize =(sizeof(log_t));

	mqdes1 = mq_open("/msgqueue2",O_CREAT|O_RDWR , 0666,&attr1);	//Open message queue
	if(mqdes1 ==-1){
		perror("\n\rFailed to open message queue 1 ");
	}

	status = pthread_create(&logger,NULL,logger_thread_callback,NULL);	//Create logger thread
	if(status !=0){
		printf("\n\rLogger thread not created successfully");

	}
	status = pthread_create(&statemachine,NULL,statemachine_thread_callback,NULL);	//create statemachine thread
	if(status !=0){
		printf("\n\rState  machine thread not created successfully");

	}
	//	pthread_kill(child1,SIGUSR2);
	status=pthread_join(logger,NULL);		//Wait for logger thread to finish
	if(status !=0){
		printf("\n\rJoining of logger thread not successfull");
	}
	status=pthread_join(statemachine,NULL);		//Wait for statemachine thread to finish
	if(status !=0){
		printf("\n\rJoining of statemachine not successfull");
	}

	mq_close(mqdes1);	//close the queue
	mq_unlink("/msgqueue2"); //unlink the message queue	
	//pthread_exit(NULL);

}

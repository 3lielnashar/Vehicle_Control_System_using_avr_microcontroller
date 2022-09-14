/*
 * car_system.c
 *
 *  Created on: Sep 5, 2021
 *      Author: aliel
 */
#include "car_system.h"
#include <stdio.h>
#include <stdlib.h>
/*
 listing all available sensors
 */
void sensors_menu (void)
{
	printf(" sensors set menu  :\n");
	printf("Turn off the engine : [a]\n");
	printf("Set the traffic light color : [b]\n");
	printf("Set the room temperature (Temperature Sensor) : [c]\n");
	printf("Set the engine temperature (Engine Temperature Sensor) : [d]\n");
}
/*
 according to a certain traffic light colour the speed will set
 */
void traffic_light(uint8* colour,uint32* speed)
{
   printf("if the colour is 'G' the vehicle speed will be 100 km/hr \n");
   printf("if the colour is 'O' the vehicle speed will be 30 km/hr \n");
   printf("if the colour is 'R' the vehicle speed will be 0 km/hr \n");
   scanf (" %c",colour);
   switch(*colour)
   {
   case 'g':
   case 'G':
	   *speed = 100;
	   break;
   case 'o':
   case 'O':
   	   *speed = 30;
   	   break;
   case 'r':
   case 'R':
   	   *speed = 0;
   	   break;
   default :
	   printf("please enter an appropriate colour from the list \n");
	   traffic_light(colour,speed);
   }
}
/*
 according to a certain Room temperature from the
 user the AC will set to ON or OFF
 */
void room_temperature(float* temp, uint8* AC_mode)
{

	printf("please enter the room temperature : ");
	scanf(" %f",temp);

	if (*temp<10)
	{
		*AC_mode = 1; // AC_mode is ON
		*temp =20;
	}
	else if (*temp >30)
	{
		*AC_mode = 1;
		*temp =20;
	}
	else
		*AC_mode = 0; //AC_mode is OFF
}
/*
 according to a certain engine temperature from the
 user the AC will set to ON or OFF
 */
void engine_temperature(float* temp, uint8* controller)
{
	printf("please enter the engine temperature :");
	scanf(" %f",temp);
	if (*temp <100 )
	{
		*temp=125;
		*controller =1; //engine controller is ON
	}
	else if (*temp >150 )
	{
			*temp=125;
			*controller =1;
    }

	else
		*controller =0; // engine controller is OFF

}

/*
 this function happens when the vehicle speed is 30km/hr
 if the temperature or the engine temperature is unknown then the user must enter
 them to calculate their equation
 */
void vehicle_speed_controller(float* temp,uint8*AC_mode,uint8* controller,float* temp_engine)
{   if(*temp == -1)
	{
	printf("please enter a specific room temperature \n");
     room_temperature(temp,AC_mode);

	}
     *AC_mode =1;
     *temp = (*temp)*5 / 4 +1;
     if(*temp_engine == -1)
     	{
     	printf("please enter a specific engine temperature \n");
     	engine_temperature(temp_engine,controller);
     	}
	*temp_engine=(*temp_engine)*5 / 4 +1;
	*controller=1;

}
/*
 here are the states of the all car sensors and states
 it displays after the system display and setting the vehicle speed
 by entering the traffic light colour
 */
void system_state_after_modifying(uint8 state,uint8*AC_mode,uint8*engine_controller,float*temp,uint32*speed,float*engine_temp)

{
	if (state == 'a')
	{
		printf(" the engine is ON \n");
		printf(" the vehicle speed is %d km/hr \n",*speed);

		if (*AC_mode == 0)
		{
			printf("AC is OFF \n");
		    printf("the temperature is %.1f \n",*temp);

		}
		else if (*AC_mode == 1)
		{
			printf("AC is ON \n");
			printf("the temperature is %.1f \n",*temp);
		}

		else
		{
			printf("AC_MOde is not defined yet \n");
			 printf("the room temperature is not defined yet \n");
		}
		if (*engine_controller == 0)
		{
			printf("the engine controller is OFF \n");
		     printf("the engine temperature is %.1f \n",*engine_temp);
		}
		else if(*engine_controller == 1)
		{
			printf("the engine controller is ON \n");
			  printf("the engine temperature is %.1f",*engine_temp);
		}
		else
		{
			printf("Engine controller is not defined yet \n");
		    printf("the engine temperature is not defined yet \n");

		}

	}
	else
	{
		printf("engine is OFF \n");
		*speed = 0;
		printf(" the vehicle speed is %d km/hr \n",*speed);

		if (*AC_mode == 0)
		{
			printf("AC is OFF \n");
		    printf("the temperature is %.1f \n",*temp);

		}
		else if (*AC_mode == 1)
		{
			printf("AC is ON \n");
			printf("the temperature is %.1f \n",*temp);
		}

		else
		{
			printf("AC_MOde is not defined yet \n");
			 printf("the room temperature is not defined yet \n");
		}
		if (*engine_controller == 0)
		{
			printf("the engine controller is OFF \n");
		     printf("the engine temperature is %.1f \n",*engine_temp);
		}
		else if(*engine_controller == 1)
		{
			printf("the engine controller is ON \n");
			  printf("the engine temperature is %.1f \n",*engine_temp);
		}
		else
		{
			printf("Engine controller is not defined yet \n");
		    printf("the engine temperature is not defined yet \n");

		}

	}
}

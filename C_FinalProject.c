/*
 ============================================================================
 Name        : c_final_project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "car_system.h"
uint8 user_input = 0;

void Check_theUserinput(void) // showing all system states
{
    printf("\n ---------------------------------------------------------------------------------------\n");
    printf("   if you need to turn on vehicle engine : [a] \n");
    printf("   if you need to turn off vehicle engine : [b] \n");
    printf("   if you need to Quit the system : [c] \n");
    printf(" ----------------------------------------------------------------------------------------\n");
    scanf(" %c",&user_input);
}

void main(void){
    uint8 sensor,traffic_light_colour=-1,AC_mode=-1,Engine_temp_controller=-1;
    uint32 vehicle_speed=0;
    float room_temp=-1,engine_temp=-1;
    /* if any sensor equals -1 that mean it is not defined yet and waiting
     for an input */
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    /* this while loop to show the system display and waiting for another user_input
    to enter the switch */
    while(1){
    Check_theUserinput();
	switch(user_input) // to determine which system will be applied
	{
	case 'a':
		system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
	  /* this while loop to display the sensors menu after
	  applying any sensor from the list */
		while (1)	{
		sensors_menu();
		scanf(" %c",&sensor);
		// this while loop takes place when a not appropriate sensor is entered
		while (sensor < 97 || sensor >100 )
		{
			printf("please enter an appropriate sensor from the list \n");
			sensors_menu();
			scanf(" %c",&sensor);
		}

		if (sensor == 'a')
	    {
			user_input='b';
			system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
			break;
		//	main();
		}
		else if (sensor=='b')
		{
			traffic_light(&traffic_light_colour,&vehicle_speed);
			if (vehicle_speed == 30)
	        vehicle_speed_controller(&room_temp,&AC_mode,&Engine_temp_controller,&engine_temp);
			system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
		}
		else if(sensor == 'c')
		{
			room_temperature(&room_temp,&AC_mode);
			system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
		}
		else if (sensor == 'd')
		{
			engine_temperature(&engine_temp,&Engine_temp_controller);
			system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
		}
	}
          break;
	case 'b':
		system_state_after_modifying(user_input,&AC_mode,&Engine_temp_controller,&room_temp,&vehicle_speed,&engine_temp);
		break;
	case 'c':
		printf("the program has been quited \n");
		return;
		break;
	default: // if the user input is not determined at input list
	    printf("please enter an appropriate input from the list \n");
	    break;
	}
    }
}


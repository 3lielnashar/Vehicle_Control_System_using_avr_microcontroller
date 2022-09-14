/*
 * C_FinalProject.h
 *
 *  Created on: Sep 5, 2021
 *      Author: aliel
 */

#ifndef CAR_SYSTEM_H_
#define CAR_SYSTEM_H_

#endif /* CAR_SYSTEM_H_ */
typedef unsigned int uint32;
typedef unsigned char uint8;
void sensors_menu (void);
void traffic_light(uint8*,uint32*);
void room_temperature(float* , uint8*);
void engine_temperature(float*, uint8*);
void vehicle_speed_controller(float*,uint8*,uint8*,float*);
void system_state_after_modifying(uint8,uint8*,uint8*,float*,uint32*,float*);

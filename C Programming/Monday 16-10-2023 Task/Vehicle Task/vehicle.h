#ifndef __VEHICLE_H_
#define __VEHICLE_H_

/*-------------Includes ----------------*/
#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"
/*------------Data Type---------------*/
typedef enum{
    OFF = 0,
    ON
}state_t;

typedef enum{
    G = 1,
    O,
    R
}color_t;

typedef struct{
    state_t engine_state;
    uint32 room_temp;
    uint32 engine_temp;
    uint32 speed;
    state_t AC;
    state_t engine_controller;
}vehicle_t;


/*-------------------- Functions Declarations-------------------- */
void display_current_vehicle_state(vehicle_t *vehicle);
color_t get_traffic_light_color();
uint32 get_room_temperature();
uint32 get_engine_temperature();
void second_menue(vehicle_t *vehicle);
void manage_speed(vehicle_t *vehicle);

#endif // __VEHICLE_H_

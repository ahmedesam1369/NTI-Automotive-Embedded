#include "vehicle.h"

void display_current_vehicle_state(vehicle_t *vehicle){
    printf("-----------------------------------------\n");
    printf("Current Vehicle State\n");
    printf("Engine State: ");
    vehicle->engine_state ? printf("ON\n") : printf("OFF\n");
    printf("AC: ");
    vehicle->AC ? printf("ON\n") : printf("OFF\n");
    printf("Vehicle Speed: %d km/hr\n",  vehicle->speed);
    printf("Room Temperature: %d\n", vehicle->room_temp);
    printf("Engine Temperature Controller: ");
    vehicle->engine_controller ? printf("ON\n") : printf("OFF\n");
    printf("Engine Temperature: %d\n", vehicle->engine_temp);
    printf("-----------------------------------------\n");
}

color_t get_traffic_light_color(){
    color_t l_var;
    printf("Choose Traffic Light Color from below: \n"
           "( 1 ) \"G\"\n"
           "( 2 ) \"O\"\n"
           "( 3 ) \"R\"\n"
           );
    scanf("%i", &l_var);
    fflush(stdin);
    return l_var;
}

uint32 get_room_temperature(){
    uint32 l_var;
    printf("Enter Room Temperature: ");
    scanf("%i", &l_var);
    fflush(stdin);
    return l_var;
}

uint32 get_engine_temperature(){
    uint32 l_var;
    printf("Enter Engine Temperature: ");
    scanf("%i", &l_var);
    fflush(stdin);
    return l_var;
}


void second_menue(vehicle_t *vehicle){
    uint32 flag2 = 1;
    uint32 choose2;
    color_t l_color;
    uint32 l_room_temp, l_engine_temp;
    while(flag2){
        manage_speed(vehicle);
        printf("\n( 1 ) Turn off the vehicle engine\n"
           "( 2 ) Set the traffic light color\n"
           "( 3 ) Set the room temperature\n"
           "( 4 ) Set the engine temperature\n");
        printf("Choose Number::: ");
        scanf("%i", &choose2);
        fflush(stdin);
        switch(choose2){
            case 1:
                /*Turn off the vehicle engine */
                vehicle->engine_state = OFF;
                display_current_vehicle_state(vehicle);
                flag2 = 0; // Return to Menu 1
            break;
            case 2:
                /* Set the traffic light color */
                l_color = get_traffic_light_color();
                if(l_color == G)
                    vehicle->speed = 100;
                else if(l_color == O)
                    vehicle->speed = 30;
                else if(l_color == R)
                    vehicle->speed = 0;
                else{/* Nothing */}
                display_current_vehicle_state(vehicle);
            break;
            case 3:
                /* Set the room temperature */
                l_room_temp = get_room_temperature();
                vehicle->room_temp = l_room_temp;
                if((l_room_temp < 10) || (l_room_temp > 30)){
                    vehicle->AC = ON;
                    vehicle->room_temp = 20;
                }else{
                    vehicle->AC = OFF;
                }
                display_current_vehicle_state(vehicle);
            break;
            case 4:
                /* Set the engine temperature */
                l_engine_temp = get_engine_temperature();
                vehicle->engine_temp = l_engine_temp;
                if((l_engine_temp < 100) || (l_engine_temp > 150)){
                    vehicle->engine_controller = ON;
                    vehicle->engine_temp = 125;
                }else{
                    vehicle->engine_controller = OFF;
                }
                display_current_vehicle_state(vehicle);

            break;
            default:
               printf("Error!! Enter Number Between 1 ~ 4 ");
        }
    }


}

void manage_speed(vehicle_t *vehicle){
    if((vehicle->speed == 30) && (vehicle->engine_state == ON)){
        vehicle->AC = ON;
        vehicle->room_temp = ((vehicle->room_temp) * (5/4)) +1;
        vehicle->engine_controller = ON;
        vehicle->engine_temp = ((vehicle->engine_temp) * (5/4)) +1;
        printf("**** Changes happens because speed is equal 30 km/hr ****\n");
        display_current_vehicle_state(vehicle);
    }else{/* Nothing*/}
}

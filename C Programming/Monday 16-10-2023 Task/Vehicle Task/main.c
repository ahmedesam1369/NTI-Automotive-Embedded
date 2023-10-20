#include "vehicle.h"

int main()
{
    vehicle_t vehicle_obj;

    vehicle_obj.engine_state = OFF;
    vehicle_obj.engine_controller = OFF;
    vehicle_obj.AC = OFF;
    vehicle_obj.speed = 0;
    vehicle_obj.engine_temp = 130;
    vehicle_obj.room_temp = 25;

    uint32 flag = 1;
    uint32 choose;
    while(flag){
        manage_speed(&vehicle_obj);
        printf("\n Choose :::: \n"
           "( 1 ) Turn on the vehicle engine\n"
           "( 2 ) Turn off the vehicle engine\n"
           "( 3 ) Quit the system\n");
        printf("Choose Number::: ");
        scanf("%i", &choose);
        fflush(stdin);
        switch(choose){
            case 1:
                /* Turn on the vehicle engine */
                vehicle_obj.engine_state = ON;
                display_current_vehicle_state(&vehicle_obj);
                second_menue(&vehicle_obj);
            break;
            case 2:
                /* Turn off the vehicle engine */
                vehicle_obj.engine_state = OFF;
                display_current_vehicle_state(&vehicle_obj);
            break;
            case 3:
                /* Quit the system */
                flag = 0;
                display_current_vehicle_state(&vehicle_obj);
                printf("System Exit Successfully\n");
            break;
            default:
                printf("Error!! Enter Number Between 1 ~ 3 ");
        }

    }

    return 0;
}

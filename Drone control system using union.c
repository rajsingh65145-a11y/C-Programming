#include <stdio.h>
#include <string.h>

union DroneData
{
    int battery;
    float altitude;
    char status[50];
};

int main()
{
    union DroneData drone;
    int choice;

    while(1)
    {
        printf("\n====== DRONE CONTROL SYSTEM ======\n");

        printf("1. Update Battery\n");
        printf("2. Update Altitude\n");
        printf("3. Update Status\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Battery Percentage: ");
                scanf("%d", &drone.battery);

                printf("Battery = %d%%\n", drone.battery);
                break;

            case 2:
                printf("Enter Drone Altitude: ");
                scanf("%f", &drone.altitude);

                printf("Altitude = %.2f meters\n", drone.altitude);
                break;

            case 3:
                printf("Enter Drone Status: ");
                scanf(" %[^\n]", drone.status);

                printf("Status = %s\n", drone.status);
                break;

            case 4:
                printf("System Closed!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
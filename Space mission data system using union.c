#include <stdio.h>
#include <string.h>

union MissionData
{
    int astronauts;
    float fuel;
    char missionName[100];
};

int main()
{
    union MissionData mission;
    int choice;

    while(1)
    {
        printf("\n====== SPACE MISSION SYSTEM ======\n");

        printf("1. Enter Astronaut Count\n");
        printf("2. Enter Fuel Capacity\n");
        printf("3. Enter Mission Name\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Number of Astronauts: ");
                scanf("%d", &mission.astronauts);

                printf("Astronaut Count = %d\n",
                       mission.astronauts);
                break;

            case 2:
                printf("Enter Fuel Capacity: ");
                scanf("%f", &mission.fuel);

                printf("Fuel = %.2f Tons\n",
                       mission.fuel);
                break;

            case 3:
                printf("Enter Mission Name: ");
                scanf(" %[^\n]", mission.missionName);

                printf("Mission = %s\n",
                       mission.missionName);
                break;

            case 4:
                printf("Mission Control Closed!\n");
                return 0;

            default:
                printf("Wrong Choice!\n");
        }
    }

    return 0;
}
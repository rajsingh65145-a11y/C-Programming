#include <stdio.h>
#include <string.h>

union SmartHome
{
    int lightStatus;
    float roomTemperature;
    char voiceCommand[100];
};

int main()
{
    union SmartHome home;
    int choice;

    while(1)
    {
        printf("\n====== SMART HOME SYSTEM ======\n");

        printf("1. Light ON/OFF\n");
        printf("2. Room Temperature\n");
        printf("3. Voice Command\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Light Status (1 = ON, 0 = OFF): ");
                scanf("%d", &home.lightStatus);

                if(home.lightStatus == 1)
                    printf("Lights are ON\n");
                else
                    printf("Lights are OFF\n");

                break;

            case 2:
                printf("Enter Room Temperature: ");
                scanf("%f", &home.roomTemperature);

                printf("Temperature = %.2f C\n",
                       home.roomTemperature);
                break;

            case 3:
                printf("Enter Voice Command: ");
                scanf(" %[^\n]", home.voiceCommand);

                printf("Voice Command Received: %s\n",
                       home.voiceCommand);
                break;

            case 4:
                printf("System Shutdown!\n");
                return 0;

            default:
                printf("Invalid Input!\n");
        }
    }

    return 0;
}
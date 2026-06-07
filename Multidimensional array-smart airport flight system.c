#include <stdio.h>

int main()
{
    int flights[2][3][6]; // 2 terminals, 3 gates, 6 flights/day
    int i, j, k;
    int totalFlights = 0;

    printf("Enter number of flights:\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTerminal %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Gate %d\n", j + 1);

            for(k = 0; k < 6; k++)
            {
                printf("Flight %d count: ", k + 1);
                scanf("%d", &flights[i][j][k]);

                totalFlights += flights[i][j][k];
            }
        }
    }

    printf("\n------ AIRPORT REPORT ------\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTerminal %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Gate %d: ", j + 1);

            for(k = 0; k < 6; k++)
            {
                printf("%d ", flights[i][j][k]);
            }
            printf("\n");
        }
    }

    printf("\nTotal Flights = %d\n", totalFlights);

    return 0;
}
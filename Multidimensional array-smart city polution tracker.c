#include <stdio.h>

int main()
{
    int pollution[3][4][7]; // 3 cities, 4 zones, 7 days
    int i, j, k;
    int max = 0, min = 1000;

    printf("Enter pollution data (AQI):\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nCity %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Zone %d\n", j + 1);

            for(k = 0; k < 7; k++)
            {
                printf("Day %d AQI: ", k + 1);
                scanf("%d", &pollution[i][j][k]);

                if(pollution[i][j][k] > max)
                    max = pollution[i][j][k];

                if(pollution[i][j][k] < min)
                    min = pollution[i][j][k];
            }
        }
    }

    printf("\n------ POLLUTION REPORT ------\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nCity %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Zone %d: ", j + 1);

            for(k = 0; k < 7; k++)
            {
                printf("%d ", pollution[i][j][k]);
            }
            printf("\n");
        }
    }

    printf("\nHighest AQI = %d\n", max);
    printf("Lowest AQI = %d\n", min);

    return 0;
}
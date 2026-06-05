#include <stdio.h>

int main()
{
    int temp[3][4][7];
    int i, j, k;
    int max, min;

    printf("Enter temperature data:\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nCity %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Week %d\n", j + 1);

            for(k = 0; k < 7; k++)
            {
                printf("Day %d Temp: ", k + 1);
                scanf("%d", &temp[i][j][k]);
            }
        }
    }

    max = temp[0][0][0];
    min = temp[0][0][0];

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            for(k = 0; k < 7; k++)
            {
                if(temp[i][j][k] > max)
                    max = temp[i][j][k];

                if(temp[i][j][k] < min)
                    min = temp[i][j][k];
            }
        }
    }

    printf("\nHighest Temperature = %d", max);
    printf("\nLowest Temperature = %d\n", min);

    return 0;
}
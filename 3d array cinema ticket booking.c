#include <stdio.h>

int main()
{
    int seats[2][5][10];
    int i, j, k;
    int booked = 0;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 5; j++)
        {
            for(k = 0; k < 10; k++)
            {
                seats[i][j][k] = 0;
            }
        }
    }

    seats[0][1][2] = 1;
    seats[0][2][5] = 1;
    seats[1][4][7] = 1;

    printf("\n----- Cinema Seat Status -----\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nScreen %d\n", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("Row %d: ", j + 1);

            for(k = 0; k < 10; k++)
            {
                printf("%d ", seats[i][j][k]);

                if(seats[i][j][k] == 1)
                    booked++;
            }

            printf("\n");
        }
    }

    printf("\nTotal Booked Seats = %d\n", booked);

    return 0;
}
#include <stdio.h>

int main()
{
    int attendance[2][5][6]; // 2 blocks, 5 rooms, 6 days
    int i, j, k;
    int present, absent;

    printf("Enter attendance (1 = present, 0 = absent):\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nBlock %d\n", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("Room %d\n", j + 1);

            present = 0;
            absent = 0;

            for(k = 0; k < 6; k++)
            {
                printf("Day %d (1/0): ", k + 1);
                scanf("%d", &attendance[i][j][k]);

                if(attendance[i][j][k] == 1)
                    present++;
                else
                    absent++;
            }

            printf("Room %d Summary -> Present: %d, Absent: %d\n",
                   j + 1, present, absent);
        }
    }

    printf("\n----- Attendance Report Completed -----\n");

    return 0;
}
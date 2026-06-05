#include <stdio.h>

int main()
{
    int marks[2][3][4];
    int i, j, k;
    int total = 0;

    printf("Enter marks for 2 classes, 3 students, 4 subjects:\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nClass %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Student %d\n", j + 1);

            for(k = 0; k < 4; k++)
            {
                printf("Subject %d Marks: ", k + 1);
                scanf("%d", &marks[i][j][k]);

                total += marks[i][j][k];
            }
        }
    }

    printf("\n----- Student Marks Data -----\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nClass %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Student %d: ", j + 1);

            for(k = 0; k < 4; k++)
            {
                printf("%d ", marks[i][j][k]);
            }

            printf("\n");
        }
    }

    printf("\nTotal Marks = %d\n", total);

    return 0;
}
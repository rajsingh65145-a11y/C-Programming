#include <stdio.h>

int main()
{
    int marks[3][4][5]; // 3 classes, 4 students, 5 subjects
    int i, j, k;
    int total, avg;

    printf("Enter marks for 3 classes, 4 students, 5 subjects:\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nClass %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Student %d\n", j + 1);
            total = 0;

            for(k = 0; k < 5; k++)
            {
                printf("Subject %d Marks: ", k + 1);
                scanf("%d", &marks[i][j][k]);
                total += marks[i][j][k];
            }

            avg = total / 5;
            printf("Average of Student %d = %d\n", j + 1, avg);
        }
    }

    printf("\n----- Complete Result Sheet -----\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nClass %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Student %d: ", j + 1);

            for(k = 0; k < 5; k++)
            {
                printf("%d ", marks[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int marks[2][3][4]; // 2 semesters, 3 students, 4 subjects
    int i, j, k;
    int total;

    printf("Enter marks for 2 semesters, 3 students, 4 subjects:\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nSemester %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Student %d\n", j + 1);
            total = 0;

            for(k = 0; k < 4; k++)
            {
                printf("Subject %d marks: ", k + 1);
                scanf("%d", &marks[i][j][k]);
                total += marks[i][j][k];
            }

            printf("Total marks of Student %d = %d\n", j + 1, total);
        }
    }

    printf("\n------ RESULT SHEET ------\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nSemester %d\n", i + 1);

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

    return 0;
}
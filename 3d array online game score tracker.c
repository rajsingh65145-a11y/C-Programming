#include <stdio.h>

int main()
{
    int score[2][3][4]; // 2 teams, 3 players, 4 matches
    int i, j, k;
    int teamTotal;

    printf("Enter game scores:\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTeam %d\n", i + 1);
        teamTotal = 0;

        for(j = 0; j < 3; j++)
        {
            printf("Player %d\n", j + 1);

            for(k = 0; k < 4; k++)
            {
                printf("Match %d score: ", k + 1);
                scanf("%d", &score[i][j][k]);

                teamTotal += score[i][j][k];
            }
        }

        printf("Total Score of Team %d = %d\n", i + 1, teamTotal);
    }

    printf("\n----- Score Board -----\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTeam %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Player %d: ", j + 1);

            for(k = 0; k < 4; k++)
            {
                printf("%d ", score[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
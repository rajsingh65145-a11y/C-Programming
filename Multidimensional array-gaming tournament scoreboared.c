#include <stdio.h>

int main()
{
    int score[2][3][5]; // 2 teams, 3 players, 5 rounds
    int i, j, k;
    int teamScore;

    printf("Enter tournament scores:\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTeam %d\n", i + 1);
        teamScore = 0;

        for(j = 0; j < 3; j++)
        {
            printf("Player %d\n", j + 1);

            for(k = 0; k < 5; k++)
            {
                printf("Round %d score: ", k + 1);
                scanf("%d", &score[i][j][k]);

                teamScore += score[i][j][k];
            }
        }

        printf("Total Score of Team %d = %d\n", i + 1, teamScore);
    }

    printf("\n------ SCOREBOARD ------\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nTeam %d\n", i + 1);

        for(j = 0; j < 3; j++)
        {
            printf("Player %d: ", j + 1);

            for(k = 0; k < 5; k++)
            {
                printf("%d ", score[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
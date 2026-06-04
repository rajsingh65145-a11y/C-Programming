#include <stdio.h>

struct Player
{
    char name[50];
    int matches;
    int runs;
};

int main()
{
    struct Player p[2];
    int i;

    for(i = 0; i < 2; i++)
    {
        printf("\nEnter Player Name: ");
        scanf("%s", p[i].name);

        printf("Enter Matches Played: ");
        scanf("%d", &p[i].matches);

        printf("Enter Total Runs: ");
        scanf("%d", &p[i].runs);
    }

    printf("\n------ Player Records ------\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nName    : %s", p[i].name);
        printf("\nMatches : %d", p[i].matches);
        printf("\nRuns    : %d\n", p[i].runs);
    }

    return 0;
}
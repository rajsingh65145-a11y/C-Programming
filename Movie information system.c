#include <stdio.h>

struct Movie
{
    char name[50];
    char director[50];
    int releaseYear;
};

int main()
{
    struct Movie m;

    printf("Enter Movie Name: ");
    scanf(" %[^\n]", m.name);

    printf("Enter Director Name: ");
    scanf(" %[^\n]", m.director);

    printf("Enter Release Year: ");
    scanf("%d", &m.releaseYear);

    printf("\n------ Movie Details ------\n");

    printf("Movie Name  : %s\n", m.name);
    printf("Director    : %s\n", m.director);
    printf("ReleaseYear : %d\n", m.releaseYear);

    return 0;
}
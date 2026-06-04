#include <stdio.h>

struct Laptop
{
    char company[50];
    char processor[50];
    int ram;
};

int main()
{
    struct Laptop l[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter Company Name: ");
        scanf("%s", l[i].company);

        printf("Enter Processor Name: ");
        scanf("%s", l[i].processor);

        printf("Enter RAM Size (GB): ");
        scanf("%d", &l[i].ram);
    }

    printf("\n------ Laptop Details ------\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nCompany  : %s", l[i].company);
        printf("\nProcessor: %s", l[i].processor);
        printf("\nRAM      : %d GB\n", l[i].ram);
    }

    return 0;
}
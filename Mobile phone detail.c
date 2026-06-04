#include <stdio.h>

struct Mobile
{
    char brand[50];
    char model[50];
    float price;
};

int main()
{
    struct Mobile m[2];
    int i;

    for(i = 0; i < 2; i++)
    {
        printf("\nEnter Mobile Brand: ");
        scanf("%s", m[i].brand);

        printf("Enter Mobile Model: ");
        scanf("%s", m[i].model);

        printf("Enter Mobile Price: ");
        scanf("%f", &m[i].price);
    }

    printf("\n------ Mobile Details ------\n");

    for(i = 0; i < 2; i++)
    {
        printf("\nBrand : %s", m[i].brand);
        printf("\nModel : %s", m[i].model);
        printf("\nPrice : %.2f\n", m[i].price);
    }

    return 0;
}
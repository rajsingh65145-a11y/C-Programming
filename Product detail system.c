#include <stdio.h>

struct Product
{
    int code;
    char name[50];
    float price;
};

int main()
{
    struct Product p;

    printf("Enter Product Code: ");
    scanf("%d", &p.code);

    printf("Enter Product Name: ");
    scanf("%s", p.name);

    printf("Enter Product Price: ");
    scanf("%f", &p.price);

    printf("\n----- Product Details -----\n");

    printf("Code  : %d\n", p.code);
    printf("Name  : %s\n", p.name);
    printf("Price : %.2f\n", p.price);

    return 0;
}
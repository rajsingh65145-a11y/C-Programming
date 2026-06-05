#include <stdio.h>

int main()
{
    int stock[3][4][5];
    int i, j, k;
    int total = 0;

    printf("Enter stock for 3 warehouses, 4 sections, 5 products:\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nWarehouse %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Section %d\n", j + 1);

            for(k = 0; k < 5; k++)
            {
                printf("Product %d Quantity: ", k + 1);
                scanf("%d", &stock[i][j][k]);

                total += stock[i][j][k];
            }
        }
    }

    printf("\n----- Warehouse Stock Report -----\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nWarehouse %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Section %d: ", j + 1);

            for(k = 0; k < 5; k++)
            {
                printf("%d ", stock[i][j][k]);
            }

            printf("\n");
        }
    }

    printf("\nTotal Stock Quantity = %d\n", total);

    return 0;
}
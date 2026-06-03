#include <stdio.h>
#include <conio.h>

int main()
{
    int i, j, k, n;

    n = 3;  // Number of rows

    for(i = 1; i <= n; i++)
    {
        // Print spaces
        for(k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        // Print symbols
        for(j = 1; j <= i; j++)
        {
            if(i % 2 != 0)
                printf("* ");
            else
                printf("+ ");
        }

        printf("\n");
    }

    getch();
    return 0;
}
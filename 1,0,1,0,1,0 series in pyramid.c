#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
            printf("1");
        else
            printf("0");
            
        if(i < n)
            printf(",");  // for comma separation
    }
    
    return 0;
}
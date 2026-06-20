#include <stdio.h>

// Recursive function to calculate sum of digits
int sumOfDigits(int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    return (n % 10) + sumOfDigits(n / 10);
}

// Recursive function to count digits
int countDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return 1 + countDigits(n / 10);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        num = -num;
    }

    int sum = sumOfDigits(num);
    int digits = countDigits(num);

    printf("\nNumber: %d\n", num);
    printf("Sum of Digits: %d\n", sum);
    printf("Total Digits: %d\n", digits);

    return 0;
}
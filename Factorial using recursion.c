#include <stdio.h>

// recursive function
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // base case
    }
    return n * factorial(n - 1);  // recursive call
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }

    return 0;
}
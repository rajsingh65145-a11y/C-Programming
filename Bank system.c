#include <stdio.h>

struct Bank
{
    int accNo;
    char name[50];
    float balance;
};

int main()
{
    struct Bank b;

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);

    printf("Enter Account Holder Name: ");
    scanf("%s", b.name);

    printf("Enter Balance: ");
    scanf("%f", &b.balance);

    printf("\n------ Account Details ------\n");

    printf("Account Number : %d\n", b.accNo);
    printf("Holder Name    : %s\n", b.name);
    printf("Balance        : %.2f\n", b.balance);

    return 0;
}
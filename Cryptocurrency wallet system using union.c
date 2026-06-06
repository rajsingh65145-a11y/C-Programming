#include <stdio.h>
#include <string.h>

union Wallet
{
    float bitcoin;
    float ethereum;
    char owner[100];
};

int main()
{
    union Wallet wallet;
    int choice;

    while(1)
    {
        printf("\n====== CRYPTO WALLET SYSTEM ======\n");

        printf("1. Store Bitcoin\n");
        printf("2. Store Ethereum\n");
        printf("3. Store Owner Name\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Bitcoin Amount: ");
                scanf("%f", &wallet.bitcoin);

                printf("Bitcoin Stored = %.4f BTC\n",
                       wallet.bitcoin);
                break;

            case 2:
                printf("Enter Ethereum Amount: ");
                scanf("%f", &wallet.ethereum);

                printf("Ethereum Stored = %.4f ETH\n",
                       wallet.ethereum);
                break;

            case 3:
                printf("Enter Owner Name: ");
                scanf(" %[^\n]", wallet.owner);

                printf("Wallet Owner = %s\n",
                       wallet.owner);
                break;

            case 4:
                printf("Program Ended!\n");
                return 0;

            default:
                printf("Invalid Option!\n");
        }
    }

    return 0;
}
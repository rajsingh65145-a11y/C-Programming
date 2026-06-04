#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchBook(struct Book library[], int count);
void issueBook(struct Book library[], int count);
void returnBook(struct Book library[], int count);
void deleteBook(struct Book library[], int *count);

int main()
{
    struct Book library[100];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n=====================================");
        printf("\n      LIBRARY MANAGEMENT SYSTEM");
        printf("\n=====================================");

        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Delete Book");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook(library, &count);
                break;

            case 2:
                displayBooks(library, count);
                break;

            case 3:
                searchBook(library, count);
                break;

            case 4:
                issueBook(library, count);
                break;

            case 5:
                returnBook(library, count);
                break;

            case 6:
                deleteBook(library, &count);
                break;

            case 7:
                printf("\nProgram Closed Successfully!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void addBook(struct Book library[], int *count)
{
    printf("\nEnter Book ID: ");
    scanf("%d", &library[*count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[*count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[*count].author);

    printf("Enter Quantity: ");
    scanf("%d", &library[*count].quantity);

    printf("Enter Book Price: ");
    scanf("%f", &library[*count].price);

    (*count)++;

    printf("\nBook Added Successfully!\n");
}

void displayBooks(struct Book library[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n====================================================================");
    printf("\nID\tTitle\t\tAuthor\t\tQuantity\tPrice");
    printf("\n====================================================================");

    for (i = 0; i < count; i++)
    {
        printf("\n%d\t%s\t\t%s\t\t%d\t\t%.2f",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].quantity,
               library[i].price);
    }

    printf("\n====================================================================\n");
}

void searchBook(struct Book library[], int count)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            printf("\nBook Found!");
            printf("\nBook ID   : %d", library[i].id);
            printf("\nTitle     : %s", library[i].title);
            printf("\nAuthor    : %s", library[i].author);
            printf("\nQuantity  : %d", library[i].quantity);
            printf("\nPrice     : %.2f\n", library[i].price);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nBook Not Found!\n");
    }
}

void issueBook(struct Book library[], int count)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            found = 1;

            if (library[i].quantity > 0)
            {
                library[i].quantity--;

                printf("\nBook Issued Successfully!");
                printf("\nRemaining Quantity: %d\n",
                       library[i].quantity);
            }
            else
            {
                printf("\nBook Out of Stock!\n");
            }

            break;
        }
    }

    if (!found)
    {
        printf("\nBook Not Found!\n");
    }
}

void returnBook(struct Book library[], int count)
{
    int id, i, found = 0;
    int lateDays;
    float fine;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            found = 1;

            library[i].quantity++;

            printf("Enter Number of Late Days: ");
            scanf("%d", &lateDays);

            fine = lateDays * 5;

            printf("\nBook Returned Successfully!");
            printf("\nFine Amount: %.2f\n", fine);

            break;
        }
    }

    if (!found)
    {
        printf("\nBook Not Found!\n");
    }
}

void deleteBook(struct Book library[], int *count)
{
    int id, i, j, found = 0;

    printf("\nEnter Book ID to Delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (library[i].id == id)
        {
            found = 1;

            for (j = i; j < *count - 1; j++)
            {
                library[j] = library[j + 1];
            }

            (*count)--;

            printf("\nBook Deleted Successfully!\n");

            break;
        }
    }

    if (!found)
    {
        printf("\nBook Not Found!\n");
    }
}
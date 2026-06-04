#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee e[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter Employee ID: ");
        scanf("%d", &e[i].id);

        printf("Enter Employee Name: ");
        scanf("%s", e[i].name);

        printf("Enter Salary: ");
        scanf("%f", &e[i].salary);
    }

    printf("\n------ Employee Records ------\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nID: %d", e[i].id);
        printf("\nName: %s", e[i].name);
        printf("\nSalary: %.2f\n", e[i].salary);
    }

    return 0;
}
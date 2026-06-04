#include <stdio.h>

struct Patient
{
    int id;
    char name[50];
    int age;
};

int main()
{
    struct Patient p;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf("%s", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("\n------ Patient Record ------\n");

    printf("Patient ID   : %d\n", p.id);
    printf("Patient Name : %s\n", p.name);
    printf("Age          : %d\n", p.age);

    return 0;
}
#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
    char grade;
};

void addStudent(struct Student s[], int *count);
void displayStudents(struct Student s[], int count);
void searchStudent(struct Student s[], int count);
void updateStudent(struct Student s[], int count);
void deleteStudent(struct Student s[], int *count);
void sortStudents(struct Student s[], int count);

int main()
{
    struct Student students[100];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n==============================");
        printf("\n STUDENT MANAGEMENT SYSTEM");
        printf("\n==============================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Sort Students by Marks");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                break;

            case 6:
                sortStudents(students, count);
                break;

            case 7:
                printf("\nProgram Exited Successfully!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void addStudent(struct Student s[], int *count)
{
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    if (s[*count].marks >= 90)
        s[*count].grade = 'A';
    else if (s[*count].marks >= 75)
        s[*count].grade = 'B';
    else if (s[*count].marks >= 60)
        s[*count].grade = 'C';
    else if (s[*count].marks >= 40)
        s[*count].grade = 'D';
    else
        s[*count].grade = 'F';

    (*count)++;

    printf("\nStudent Added Successfully!\n");
}

void displayStudents(struct Student s[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Students Found!\n");
        return;
    }

    printf("\n---------------------------------------------------");
    printf("\nRoll\tName\t\tMarks\tGrade");
    printf("\n---------------------------------------------------");

    for (i = 0; i < count; i++)
    {
        printf("\n%d\t%s\t\t%.2f\t%c",
               s[i].roll,
               s[i].name,
               s[i].marks,
               s[i].grade);
    }

    printf("\n---------------------------------------------------\n");
}

void searchStudent(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!");
            printf("\nRoll Number : %d", s[i].roll);
            printf("\nName        : %s", s[i].name);
            printf("\nMarks       : %.2f", s[i].marks);
            printf("\nGrade       : %c\n", s[i].grade);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent Not Found!\n");
    }
}

void updateStudent(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            if (s[i].marks >= 90)
                s[i].grade = 'A';
            else if (s[i].marks >= 75)
                s[i].grade = 'B';
            else if (s[i].marks >= 60)
                s[i].grade = 'C';
            else if (s[i].marks >= 40)
                s[i].grade = 'D';
            else
                s[i].grade = 'F';

            printf("\nStudent Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent Not Found!\n");
    }
}

void deleteStudent(struct Student s[], int *count)
{
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < *count; i++)
    {
        if (s[i].roll == roll)
        {
            for (j = i; j < *count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            (*count)--;

            printf("\nStudent Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent Not Found!\n");
    }
}

void sortStudents(struct Student s[], int count)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (s[i].marks < s[j].marks)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\nStudents Sorted By Marks Successfully!\n");
}
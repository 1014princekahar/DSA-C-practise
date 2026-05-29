#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int f = -1, r = -1, sq[SIZE];

void clearScreen();
void insert();
void delete();
void display();

int main()
{
    int op;
    clearScreen();
    
    do
    {
        printf("\n===> Select Queue Operation <===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            clearScreen();
            insert();
            break;

        case 2:
            clearScreen();
            delete();
            break;

        case 3:
            clearScreen();
            display();
            break;

        case 4:
            clearScreen();
            printf("Exititng...\n");
            break;

        default:
            clearScreen();
            printf("Invalid Operation...\n");
        }
    } while (op != 4);
    return 0;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void insert()
{
    if (r == SIZE - 1)
        printf("Queue is Full\n");

    else
    {
        int val;

        printf("Enter a Value : ");
        scanf("%d", &val);

        f = 0;

        r++;
        sq[r] = val;

        printf("%d is insert succesfully....\n", val);
    }
}

void delete()
{
    if (f == r)
    {
        f = -1;
        r = -1;
        printf("Now Queue is Empty...\n");
    }
    else
    {
        printf("%d is deleted...\n", sq[f]);
        f++;
    }
}

void display()
{
    if (f == -1)
    {
        printf("Queue is Empty");
        return;
    }

    for (int i = f; i <= r; i++)
        printf("%d\t", sq[i]);
    printf("\n");
}
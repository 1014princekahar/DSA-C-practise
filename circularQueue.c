#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int circularQueue[SIZE];
int f = -1, r = -1;

void clearScreen();
void insertQueue();
void deleteQueue();
void display();

int main()
{
    clearScreen();

    int choice;
    do
    {
        printf(" =====> Circular Queue Operations <=====\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertQueue();
            break;

        case 2:
            deleteQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting....\n");
            break;

        default:
            printf("Incorrected Choice.....\n");
            break;
        }
    } while (choice != 4);
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

void insertQueue()
{
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        circularQueue[r] = value;
        printf("r = %d\nf = %d\n", r, f);
    }

    else if (r == f - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    else if (f != 0)
    {
        if (r == SIZE - 1)
        {
            r = 0;
            circularQueue[r] = value;
            printf("r = %d\nf = %d\n", r, f);
        }
        else
        {
            r++;
            circularQueue[r] = value;
            printf("r = %d\nf = %d\n", r, f);
        }
    }
    else if (r == SIZE - 1)
    {
        printf("\n** Queue Is Full **\n");
        return;
    }

    else
    {
        circularQueue[++r] = value;
        printf("r = %d\nf = %d\n", r, f);
    }
}

void deleteQueue()
{
    if (f == r)
    {
        printf("\n** Queue Is Empty **\n");
        return;
    }

    else
    {
        printf("\n *%d Deleted Successfully *\n", circularQueue[f]);
        f++;
        printf("r = %d\nf= %d\n", r, f);
    }
}

void display()
{
    for (int i = 0; i <= 4; i++)
    {
        printf("%d \t", circularQueue[i]);
    }
    printf("\n");
}

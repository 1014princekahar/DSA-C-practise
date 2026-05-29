#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
int f = -1, r = -1;

void clearScreen();
int isFull();
int isEmpty();

void outputRestriction();

void insertFromFront(int value);
void insertFromRear(int value);

void deleteFromFront();
void deleteFromRear();

void insert();
void delete();

void displayQueue();

int main()
{
    clearScreen();
    outputRestriction();
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

int isFull()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        return 1;
    }

    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }

    return 0;
}

void outputRestriction()
{
    int choice;
    do
    {
        printf("\n =====> Output Restriction Options <===== \n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
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
            displayQueue();
            break;

        case 4:
            printf("Exiting.....");
            break;

        default:
            printf("You Have choose wrong option....");
        }

    } while (choice != 4);
}

void insert()
{
    int choice;
    int value;
    printf("\n ====> Insert Options <==== \n");
    
        printf("1. Insert From Front \n");
        printf("2. Insert From Rear \n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Insert From Front \n");
            printf("Insert Value: ");
            scanf("%d", &value);
            insertFromFront(value);
        }
        else if (choice == 2)
        {
            printf("Insert From Rear \n");
            printf("Insert Value: ");
            scanf("%d", &value);
            insertFromRear(value);
        }
        else
        {
            printf("You have choose wrong option....");
        }
}

void insertFromFront(int value)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("Inserted %d from the front.\n", value);
        // f = 1; // Mark that an element has been inserted from the front
        printf("rear = %d\nfront = %d\n", rear, front);
    }

    else if (rear == front - 1 || (front == 0 && rear == SIZE -1 ))
    {
        printf("Queue is Full\n");
        return;
    }

    else if (front == 0)
    {
        front = SIZE - 1;
        queue[front] = value;
        printf("Inserted %d from the front.\n", value);
        // f = 1; // Mark that an element has been inserted from the front

        printf("rear = %d\nfront = %d\n", rear, front);
    }
    
    // else if ( front < rear) 
    // {

    // }
    else
    {
        queue[--front] = value;
        printf("Inserted %d from the front.\n", value);
        // f = 1; // Mark that an element has been inserted from the front

        printf("rear = %d\nfront = %d\n", rear, front);
    }
}

void insertFromRear(int value)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("Inserted %d from the front.\n", value);
        // f = 1; // Mark that an element has been inserted from the front
        printf("rear = %d\nfront = %d\n", rear, front);
    }

    else if (rear == front - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    else if (front != 0)
    {
        if (rear == SIZE - 1)
        {
            rear = 0;
            queue[rear] = value;
            printf("Inserted %d from the front.\n", value);
            // f = 1; // Mark that an element has been inserted from the front

            printf("rear = %d\nfront = %d\n", rear, front);
        }
        else
        {
            queue[++rear] = value;
            printf("Inserted %d from the front.\n", value);
            // f = 1; // Mark that an element has been inserted from the front

            printf("rear = %d\nfront = %d\n", rear, front);
        }
    }

    else if (rear == SIZE - 1)
    {
        printf("\n** Queue Is Full **\n");
        return;
    }

    else
    {
        queue[++rear] = value;
        // printf("Inserted %d from the front.\n", value);
        // f = 1; // Mark that an element has been inserted from the front

        printf("r = %d\nf = %d\n", rear, front);
    }
}

void delete()
{
    int choice;
    printf("\n =====> Delete Options <===== \n");
    if (r == -1 && f == -1)
    {
        printf("1. Delete From Front \n");
        printf("2. Delete From Rear \n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            deleteFromFront();
            f = 0;
        }
        else if (choice == 2)
        {
            deleteFromRear();
            r = 0;
        }
        else
        {
            printf("You have choose wrong option....");
        }

    }

    else if (r == -1)
    {
        deleteFromFront();
    }

    else
    {
        deleteFromRear();
        r = 0;
    }

}

void deleteFromFront()
{
    if (isEmpty())
    {
        printf("Queue Underflow...\n");
        return;
    }

    printf("%d Deleted From Front\n", queue[front]);

    if (front == rear)
    {
        queue[front] = 0;
        front = rear = -1;
    }

    else if (front == SIZE - 1)
    {
        queue[front] = 0;
        front = 0;
    }

    else
    {
        queue[front] = 0;
        front++;
    }
}

void deleteFromRear()
{
    if (isEmpty())
    {
        printf("Queue Underflow...\n");
        return;
    }

    printf("%d Deleted From Rear\n", queue[rear]);

    if (front == rear)
    {
        queue[rear] = 0;
        front = rear = -1;
    }

    else if (rear == 0)
    {

        queue[rear] = 0;
        rear = SIZE - 1;
    }

    else
    {
        queue[rear] = 0;
        rear--;
    }
}

void displayQueue()
{
    for (int i = 0; i <= SIZE - 1; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\nQueue displayed successfully.\n");
}

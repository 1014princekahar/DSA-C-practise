#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;

void clearScreen();
void operations();
void Switch();
int empty(); // Stack Underflow
int full();  // Stack Overflow
void Push();
void pop();
void display();

int main()
{
    clearScreen();
    Switch();

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

void operations()
{
    printf("\n====> Stack Operations <====\n");
    printf(" 1. Push\n");
    printf(" 2. Pop\n");
    printf(" 3. Display\n");
    printf(" 4. Exit\n");
}

void Switch()
{
    int ch;

    do
    {
        operations();
        printf("Enter Your Choice ( 1 - 4 ): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting Program ....\n");
            break;

        default:
            printf("Invalid Choice ....\n");
        }
    } while (ch != 4);
}

int empty()
{
    if (top == -1)
        return 1;
    return 0;
}

int full()
{
    if (top == SIZE - 1)
        return 1;
    return 0;
}

void Push()
{
    if (full() == 1)
        printf("Stack is Overflow\n");
    else
    {
        int push_val;

        printf("Enter Value To Push: ");
        scanf("%d", &push_val);

        top++;
        stack[top] = push_val;

        printf("%d is Push Successfully in Stack ....\n", push_val);
    }
}

void pop()
{
    if (empty() == 1)
        printf("Stack is Underflow\n");
    else
    {
        int pop_val = stack[top];
        top--;

        printf("%d is pop Successfully from Stack ....\n", pop_val);
    }
}

void display()
{
    if (empty() == 1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack Elements: ");
        for (int i = 0; i <= top; i++)
            printf(" | %d |", stack[i]);
        printf("\n");
    }
}

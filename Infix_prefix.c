#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char infix[MAX], temp[MAX], stack[MAX], prefix[MAX], temp2[MAX];
int top = -1;

void clearScreen();
void reverse(char str[MAX]);
void push(char ch);
char pop();

int main()
{
    int j = 0;
    clearScreen();
    printf("Enter Your Expression: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    strcpy(temp2, infix);
    reverse(temp2);

    printf("Reversed Expression: %s\n", temp);

    for (int i = 0; temp[i] != '\0'; i++)
    {
        char ch = temp[i];
        switch (ch)
        {

        case ')':
            push(ch);
            break;

        case '(':
            while (top != -1 && stack[top] != ')')
                prefix[j++] = pop();
            if (top != -1)
                pop();
            // push(ch);
            break;

        case '^':
            push(ch);
            break;

        case '*':
        case '/':
            while (top != -1 && stack[top] == '^')
                prefix[j++] = pop();
            push(ch);
            break;

        case '+':
        case '-':
            while (top != -1 && (stack[top] == '^' || stack[top] == '*' || stack[top] == '/' ))
                prefix[j++] = pop();
            push(ch);
            break;

        case ' ':
            continue;

        default:
            prefix[j++] = ch;
        }
    }

    while (stack[top] != -1)
    {
        if (stack[top] == '(' || stack[top] == ')')
            pop();
        else
            prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);

    strcpy(prefix, temp);

    printf("\nInfix Expression: %s", infix);
    printf("\nPrefix Expression: %s", prefix);
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

void reverse(char str[MAX])
{
    int len = strlen(str);
    int j = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        temp[j] = str[i];
        j++;
    }

    temp[len] = '\0';
}

void push(char push_val)
{
    stack[++top] = push_val;
}

char pop()
{
    char pop_value = stack[top--];

    return pop_value;
}


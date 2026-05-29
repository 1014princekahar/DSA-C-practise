#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

void clearScreen();
void validation(char[]);
int operator(char);
int operand(char);
int precidence(char);
void push(char);
char pop();

int main()
{
    clearScreen();

    int j = 0, k = 0;

    printf("Enter Your Expression: ");
    if (!fgets(infix, sizeof(infix), stdin))
        return 1;

    infix[strcspn(infix, "\n")] = '\0';

    validation(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char curr = infix[i];
        if (curr == ' ')
            continue;

        if (operand(curr))
            postfix[k++] = curr;

        else if (curr == '(')
            push(curr);

        else if (curr == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if (top != -1 && stack[top] == '(')
                pop();
        }

        else if (operator(curr))
        {
            while (top != -1 && precidence(curr) <= precidence(stack[top]))
                postfix[k++] = pop();
            push(curr);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

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

int operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int operand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void validation(char expr[])
{
    int paren_check = 0;
    int length = strlen(expr);

    if (length == 0)
    {
        printf("Empty expression is not valid.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++)
    {
        char curr = expr[i];
        char next = (i + 1 < length ? expr[i + 1] : '\0');

        if (operand(curr) || operator(curr) || curr == '(' || curr == ')' || curr == ' ')
        {
            if (curr == '(')
                paren_check++;
            else if (curr == ')')
            {
                paren_check--;
                if (paren_check < 0)
                {
                    printf("Unmatched closing parenthesis detected.\n");
                    exit(1);
                }
            }
        }

        else
        {
            printf("Invalid character '%c' in expression.\n", curr);
            exit(1);
        }

        if (next != '\0')
        {
            if (operand(curr) && operand(next))
            {
                printf("Invalid expression: consecutive operands '%c%c'.\n", curr, next);
                exit(1);
            }
            if (operator(curr) && operator(next))
            {
                printf("Invalid expression: consecutive operators '%c%c'.\n", curr, next);
                exit(1);
            }
            if (curr == ')' && next == '(')
            {
                printf("Invalid expression: missing operator between ')' and '('.\n");
                exit(1);
            }
        }
    }

    if (paren_check != 0)
    {
        printf("Unmatched parentheses: open and close count must be equal.\n");
        exit(1);
    }
}

int precidence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop()
{
    if (top != -1)
        return stack[top--];
    return '\0';
}

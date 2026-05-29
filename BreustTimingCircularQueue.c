
#include <stdio.h>

int main()
{
    int p1, p2, p3, q_t, f1, f2, f3;
    f1 = f2 = f3 = 0;
    printf("Enter Burst Time Of P1: ");
    scanf("%d", &p1);

    printf("Enter Burst Time Of P2: ");
    scanf("%d", &p2);

    printf("Enter Burst Time Of P3: ");
    scanf("%d", &p3);

    printf("Enter Quantum Time: ");
    scanf("%d", &q_t);

    while (f1 == 0 || f2 == 0 || f3 == 0)
    {
        if (p1 >= 0 && f1 == 0)
        {
            if (p1 <= q_t)
            {
                f1 = 1;
                printf("\nP1 executes for %d units , Task Completed", q_t - p1);
                p1 = p1 - q_t;
            }

            else
            {
                printf("\nP1 executes for %d units", q_t);
                p1 -= q_t;
            }

        }

        if (p2 >= 0 && f2 == 0)
        {
            if (p2 <= q_t)
            {
                f2 = 1;
                printf("\nP2 executes for %d units , Task Completed", q_t - p2);
                p2 = p2 - q_t;
            }

            else
            {
                printf("\nP2 executes for %d units", q_t);
                p2 -= q_t;
            }

        }

        if (p3 >= 0 && f3 == 0)
        {
            if (p3 <= q_t)
            {
                f3 = 1;
                printf("\nP3 executes for %d units , Task Completed", q_t - p3);
                p3 = p3 - q_t;
            }

            else
            {
                printf("\nP3 executes for %d units", q_t);
                p3 -= q_t;
            }
        }
    }
    return 0;
}
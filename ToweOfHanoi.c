#include <stdio.h>
#include <stdlib.h>

void clearScreen();

int main()
{
    clearScreen();
    
    int nDisks;
    printf("Enter Number of Disks: ");
    scanf("%d", &nDisks);

    TowerOfHanoi(nDisks, 'A', ' B', 'C');

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

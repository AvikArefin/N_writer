#include <stdio.h>
#include <conio.h>

int main()
{
    char x;

    for (int i = 0; i < 10; i++)
    {
        x = getch();
        printf("%c", x);
        if (x == ' ')
        {

            printf("NEXT WORD");
        }
    }
    return 0;
}
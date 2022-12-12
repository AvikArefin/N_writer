#include <conio.h>
#include <stdio.h>

#define CLEAR_SCREEN printf("\033[2J")

#define GOTOXY(x, y) printf("\033[%d;%dH", x, y)

#define MOVE_UP(x) printf("\033[%dA", x)
#define MOVE_DOWN(x) printf("\033[%dB", x)
#define MOVE_FORWARD(x) printf("\033[%dC", x)
#define MOVE_BACKWARD(x) printf("\033[%dD", x)

void main()
{
    CLEAR_SCREEN;
    GOTOXY(1, 1);
    // MOVE_DOWN(4);
    // print current location of x.
    printf("current location of x is:");
    getch();
}

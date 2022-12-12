#include <stdio.h>
#include "../conio.c"

#define CLEAR_SCREEN() printf("\033[2J")
#define ERASE_LINE() printf("\33[2K")
#define RETURN_CARRIAGE() printf("\r")

#define GOTOXY(x, y) printf("\033[%d;%dH", x, y)
#define MOVE_DOWN(x) printf("\033[%dB", x)
#define MOVE_UP(x) printf("\033[%dA", x)
#define MOVE_FORWARD(x) printf("\033[%dC", x)

void notify(char *str)
{
    // GOTO THE NOTICEBAR
    int x = c_wherex();
    int y = c_wherey();

    MOVE_DOWN(4);
    ERASE_LINE();
    printf("COMMAND: %s - %d %d", str, x, y);
    MOVE_UP(4);
    RETURN_CARRIAGE();
    MOVE_FORWARD(x - 2);
    // GOTOXY(x, y);
}

// Test 1 : if conio.c is working - Done
// Test 2: if c_getch() is working - Done
int main()
{
    CLEAR_SCREEN();
    GOTOXY(0, 0);
    int n = 3;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char x = c_getch();
        printf("%c", x);
        notify("Characters");
        if (x == ' ')
        {
            RETURN_CARRIAGE();
            ERASE_LINE();
            notify("White Space");
        }
        else if (x == '\x0D')
        {
            notify("Enter");
            ERASE_LINE();
            RETURN_CARRIAGE();
        }
    }
    return 0;
}
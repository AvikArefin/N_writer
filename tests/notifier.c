#include <stdio.h>
#include "../conio.c"

#define CLEAR_SCREEN() printf("\033[2J")
#define ERASE_LINE() printf("\33[2K")
#define RETURN_CARRIAGE() printf("\r")

#define GOTOXY(x, y) printf("\033[%d;%dH", y, x)
#define MOVE_DOWN(x) printf("\033[%dB", x)
#define MOVE_UP(x) printf("\033[%dA", x)
#define MOVE_FORWARD(x) printf("\033[%dC", x)

short int x_position = 1, y_position = 1;

void notify(char *str)
{
    // MOVE_DOWN(4);
    GOTOXY(4, 4);
    ERASE_LINE();
    RETURN_CARRIAGE();
    printf("COMMAND: %s @ [%d, %d]", str, x_position, y_position);
    MOVE_UP(4);
    RETURN_CARRIAGE();
    // MOVE_FORWARD(x_position);
    GOTOXY(x_position, y_position);
}

// Test 1 : if conio.c is working - Done
// Test 2: if c_getch() is working - Done
// Test 3: c_wherex is not working properly
// Find a better solution
int main()
{
    CLEAR_SCREEN();
    GOTOXY(1, 1);

    int n = 3;
    scanf("%d", &n);

    CLEAR_SCREEN();
    GOTOXY(1, 1);

    for (int i = 0; i < n; i++)
    {
        char x = c_getch();
        if (x == ' ')
        {
            RETURN_CARRIAGE();
            ERASE_LINE();
            notify("White Space");
        }
        else if (x == '\b')
        {
            x_position--; // TODO: Safety for negative values
            notify("BackSpace");
        }
        else if (x == '\x0D')
        {
            notify("Enter");
            ERASE_LINE();
            printf("\n");
            RETURN_CARRIAGE();
            y_position++;
            x_position = 1;
        }
        else if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        {
            notify("Character");
            printf("%c", x);
            x_position++;
        }
    }
    return 0;
}
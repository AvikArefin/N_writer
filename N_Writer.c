/*
N_Writer
An implementation of the popular type test application(s) available offline and online.

Version 0.2 Alpha
Developed by
Avik Arefin
ID: 2008013

Licensed under GPL 2.0
*/

#include <stdio.h>
#include "conio.c"   // For getch
#include <stdlib.h>  //
#include <time.h>    // For the timer
#include <windows.h> // For the Sleep funtion

#define ERASE_LINE() printf("\33[2K")
#define RETURN_CARRIAGE() printf("\r")
#define CLEAR_SCREEN() printf("\033[2J")

#define GOTOXY(x, y) printf("\033[%d;%dH", x, y)

#define MOVE_UP(x) printf("\033[%dA", x)
#define MOVE_DOWN(x) printf("\033[%dB", x)
#define MOVE_FORWARD(x) printf("\033[%dC", x)
#define MOVE_BACKWARD(x) printf("\033[%dD", x)

// (-1, 1) would mean 1 row down and 1 column up
void reative_cursor_mover(int row, int column)
{
    if (row > 0)
        MOVE_FORWARD(row);
    else
        MOVE_BACKWARD(column);
    if (column > 0)
        MOVE_FORWARD(column);
    else
        MOVE_BACKWARD(column);
}

int word_counter(char *input, int char_count)
{
    int word_count = 0;
    for (int i = 0; i < char_count; i++)
    {
        if (input[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count + 1;
}

int char_counter(const char *input)
{
    int char_count = 0;
    while (input[char_count] != '\0')
    {
        char_count++;
    }
    return char_count;
}

double wpm_counter(int word_count, int time_taken)
{
    return (double)(word_count * 60) / time_taken;
}

void loop_func(char *str, int no)
{
    for (int i = 0; i < no; i++)
    {
        printf("%s", str);
    }
}

const char border[] = "================================================================\n";
const char welcome[] = "Welcome to the typing test. Where only the fast remains";
const char instruction[] = "Type the text above.";

int random_num_chooser()
{
    int i = 15, k = 0;
    k = rand() % i;
    return k;
}

const char *arr[] = {
    "Baron of Hell",
    "Demon",
    "Hellknight",
    "Cyberdemon",
    "Mancubus",
    "Revenant",
    "Doomimp",
    "Zombieman",
    "Shotguy",
    "Beholder",
    "Moloch",
    "Satyr",
    "Afrit",
    "Cybermastermind",
    "Nightmarecacodemon",
};

int string_length(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

struct Power_array
{
    int word_num;
    int arr[20];
};
struct Power_array text_arr;

void text_to_write()
{
    printf("  ");
    int i = 0;
    int word_num = 0;
    while (i < 60)
    {
        int random_num = random_num_chooser();
        printf("%s", arr[random_num]);
        printf(" ");
        i += char_counter(arr[random_num]) + 1;

        text_arr.arr[word_num] = random_num;
        word_num++;
    }
    text_arr.word_num = word_num;
}

// void text_to_write()
// {
//     printf("  ");
//     int i = 0;
//     while (i < 9)
//     {
//         int random_num = random_num_chooser();
//         printf("%s", arr[random_num]);
//         printf(" ");
//         i++;
//     }
//     // printf("\n");
// }

void xprint(const char *str)
{
    printf("| %-60s |\n", str);
}

void xprintd(char *str, double db)
{
    printf("| %50s%10.3f |\n", str, db);
}

void xprinti(char *str, int i)
{
    printf("| %50s%10d |\n", str, i);
}

void go_to_output()
{ // GO TO SCREEN
    MOVE_UP(10);
    ERASE_LINE();
    RETURN_CARRIAGE();
}

void go_to_input()
{ // GOTO INPUT
    MOVE_UP(10);
    RETURN_CARRIAGE();
    MOVE_FORWARD(2);
}

void notify(char *str, int integer)
{
    // GOTO THE NOTICEBAR
    short int x = c_wherex();
    short int y = c_wherey();

    GOTOXY(12, 2);
    printf("COMMAND: %s - %d", str, integer);
    GOTOXY(x + 1, y);
}

void main_loop(int line_no)
{
    double total_time_taken = 0.0;
    int total_char_count = 0;
    int total_word_count = 0;

    while (line_no > 0)
    {
        char input[50];

        clock_t t;
        t = clock();

        // ON GOING: CHECK EACH CHACTER ONE BY ONE
        for (int i = 0; i < text_arr.word_num; i++) // one cycle for each word
        {
            notify("", i);
            int index = text_arr.arr[i];
            for (int j = 0; j < char_counter(arr[index]); j++) // one cycle for each letter
            {
                char x = c_getch();
                if (x == ' ')
                {
                    ERASE_LINE();
                    RETURN_CARRIAGE();
                    break;
                }
                else if (x == 127)
                {
                    // printf(ERASE_LINE);
                    notify("BACKSPACE", 0);
                    // TODO: Create a function that would take the cursor to a place, print a text and then come back to the specified place.
                }
                else if (x == arr[index][j])
                {
                    printf("%c", x);
                }
                else
                {
                    // printf("%c", x & '_');
                    // notify("WRONG", 0);
                    notify("", j);
                }
            }
        }

        // gets(input);

        t = clock() - t;

        double time_taken = ((double)t) / 1000;
        total_time_taken += time_taken;
        xprintd("TIME TAKEN:", total_time_taken);

        // CHARACTER & WORD COUNT:
        int char_count = char_counter(input);
        total_char_count += char_count;
        xprinti("CHARACTER COUNT:", total_char_count);
        int word_count = word_counter(input, char_count);
        total_word_count += word_count;
        xprinti("WORD COUNT:", total_word_count);

        // WORDS PER MINUTE
        double wpm = wpm_counter(total_word_count, total_time_taken);
        xprintd("WPM:", wpm);

        printf("%s", border);

        // SCREEN AND BACK TO INPUT
        go_to_output();
        text_to_write();
        go_to_input();

        line_no--;
    }
}

int main()
{
    CLEAR_SCREEN();
    GOTOXY(1, 1);

    printf("%s", border);
    xprint(welcome);
    printf("%s", border);

    xprint(instruction);

    int line_no;
    xprint("How many lines?");
    scanf("%d", &line_no);
    main_loop(line_no);

    // PAUSE FOR A BIT
    char c;
    scanf("%c", &c);
    return 0;
}
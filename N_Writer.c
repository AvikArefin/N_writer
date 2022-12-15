/*
N_Writer
A console implementation of the popular type test application(s) available offline and online.

Version 0.1 Beta

Developed by
Avik Arefin
ID: 2008013

Licensed under GPL 2.0
*/

#include <stdio.h>
#include <string.h>
#include "conio.c"   // For getch
#include <stdlib.h>  //
#include <time.h>    // For the timer
#include <windows.h> // For the Sleep funtion

#define ERASE_LINE() printf("\33[2K")
#define RETURN_CARRIAGE() printf("\r")
#define CLEAR_SCREEN() printf("\033[2J")

#define GOTOXY(x, y) printf("\033[%d;%dH", y, x)

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

int text_holder_no = 0; // ADDED
char text_holder[100] = "";

void text_to_write()
{
    printf("  ");
    int i = 0;
    int word_num = 0;      // NOT NEDDED ATM
    text_holder[0] = '\0'; // Emptying a string
    while (i < 60)
    {
        int random_num = random_num_chooser();
        printf("%s", arr[random_num]);
        printf(" ");

        strcat(text_holder, arr[random_num]); // ADDED
        strcat(text_holder, " ");

        i += char_counter(arr[random_num]) + 1;

        text_arr.arr[word_num] = random_num; // NOT NEEDED ATM
        word_num++;
    }
    text_arr.word_num = word_num; // NOT NEEDED ATM

    text_holder_no = char_counter(text_holder); // ADDED
}

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

void change_screen_text()
{
    GOTOXY(2, 2);
    ERASE_LINE();
    RETURN_CARRIAGE();

    text_to_write();

    MOVE_DOWN(3);
    RETURN_CARRIAGE();
    MOVE_FORWARD(2);
}

short int x_position = 3, y_position = 4;
void notifier(char *str)
{
    GOTOXY(2, 10);
    ERASE_LINE();
    RETURN_CARRIAGE();
    printf("COMMAND: %s @ [%d, %d]", str, x_position - 2, y_position - 3);
    MOVE_UP(3);
    RETURN_CARRIAGE();
    GOTOXY(x_position, y_position);
}

int text_holder_index = 0;

void main_loop(int line_no)
{
    double total_time_taken = 0.0;
    int total_char_count = 0;
    int total_word_count = 0;

    while (line_no > 0)
    {
        char input[70];

        clock_t t;
        t = clock();

        int n = 10;

        GOTOXY(3, 4); // Input line
        x_position = 3;
        y_position = 4;

        for (int i = 0; i < text_holder_no; i++)
        {
            char x = c_getch();
            if (x == '\b')
            {
                if (x_position > 1)
                {
                    x_position--;
                } // TODO: Safety for negative values

                if (i >= 0)
                {
                    i = i - 2;
                }
                notifier("BackSpace");
            }
            else if (x == '\x0D')
            {
                notifier("Enter");
                ERASE_LINE();
                // printf("\n");
                RETURN_CARRIAGE();
                // y_position++;
                x_position = 1;
            }
            else if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x == ' ')
            {
                notifier("Character Right");
                printf("%c", x);
                x_position++;
                if (x != text_holder[i])
                {
                    char str[2];
                    str[0] = text_holder[i];
                    str[1] = '\0';
                    notifier(str);
                }
            }
        }

        ERASE_LINE();
        RETURN_CARRIAGE();
        xprint("");

        t = clock() - t;

        // -----------------------DASHBOARD------------------------------------
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
        //----------------------------------------------------------------------
        // SCREEN AND BACK TO INPU
        change_screen_text();

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

    GOTOXY(1, 5);
    ERASE_LINE();
    xprint("");

    main_loop(line_no);
    // PAUSE FOR A BIT
    char c;
    scanf("%c", &c);
    return 0;
}
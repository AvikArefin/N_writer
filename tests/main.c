#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // For the Sleep funtion

// From https://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
#define CURSOR_UP_ONE_LINE "\033[A"
#define CURSOR_DOWN_ONE_LINE "\033[B"
#define ERASE_LINE "\33[2K"
#define RETURN_CARRIAGE "\r"
#define CURSOR_RIGHT_ONE_CHAR "\033[1C"

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

int char_counter(char *input)
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

char border[] = "================================================================\n";
char welcome[] = "Welcome to the typing test. Where only the fast remains";
char test1[] = "What do you think about this?";

int random_num_chooser(void)
{
    int i;
    int k;

    i = 15;
    k = 0;
    srand((unsigned)time(NULL));
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

void chooser()
{
    printf("| ");
    int i = 0;
    while (i < 60)
    {
        int random_num = random_num_chooser();
        xprint(arr[random_num]);

        i += string_length(arr[random_num]);
    }
}

char instruction[] = "Type the text above.";

void xprint(char *str)
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

void main_loop(int n)
{
    double total_time = 0.0;
    while (n > 0)
    {
        char input[100];

        clock_t t;
        t = clock();

        gets(input);

        t = clock() - t;

        double time_taken = ((double)t) / 1000;
        xprintd("TIME TAKEN:", time_taken);
        total_time += time_taken;
        xprintd("TOTAL TIME TAKEN:", total_time);

        int char_count = char_counter(input);

        // CHARACTER & WORD COUNT:
        xprinti("CHARACTER COUNT:", char_count);
        int word_count = word_counter(input, char_count);
        xprinti("WORD COUNT:", word_count);

        // DONE: WORDS PER MINUTE
        double wpm = wpm_counter(word_count, time_taken);
        xprintd("WPM:", wpm);

        // TIMER :

        // SCREEN_CHANGER
        loop_func(CURSOR_UP_ONE_LINE, 10);
        // Sleep(1000);
        printf(ERASE_LINE);
        printf(RETURN_CARRIAGE);
        xprint(test1);
        loop_func(CURSOR_DOWN_ONE_LINE, 3);
        loop_func(CURSOR_RIGHT_ONE_CHAR, 2);
        n--;
    }
}

int main()
{
    printf("%s", border);
    xprint(welcome);
    printf("%s", border);

    xprint(instruction);

    // TODO: Essential Test whethere the string is the same as the given string

    int n;
    xprint("how many lines?");
    scanf("%d", &n);

    main_loop(n);
    // ----------------------------------------------------------------------------
    // char input[1000];
    // clock_t t;
    // t = clock();
    // gets(input);
    // t = clock() - t;
    // double time_taken = ((double)t) / 1000;
    // xprintd("TOTAL TIME TAKEN:", time_taken);
    // int char_count = char_counter(input);
    // int char_count = 0;
    // while (input[char_count] != '\0')
    // {
    //     char_count++;
    // }
    // printf("%d", char_count);
    // // CHARACTER & WORD COUNT:
    // xprinti("CHARACTER COUNT:", char_count);
    // int word_count = word_counter(input, char_count);
    // xprinti("WORD COUNT:", word_count);
    // // DONE: WORDS PER MINUTE
    // double wpm = wpm_counter(word_count, time_taken);
    // xprintd("WPM:", wpm);
    // // TIMER :
    // // SCREEN_CHANGER
    // loop_func(CURSOR_UP_ONE_LINE, 9);
    // Sleep(1000);
    // printf(ERASE_LINE);
    // printf(RETURN_CARRIAGE);
    // xprint(test1);
    // loop_func(CURSOR_DOWN_ONE_LINE, 1);
    // loop_func(CURSOR_RIGHT_ONE_CHAR, 2);
    // -------------------------------------------------------------------------

    // PAUSE FOR A BIT
    char c;
    scanf("%c", &c);
    return 0;
}
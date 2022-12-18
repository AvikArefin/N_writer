#include <stdio.h>
#include <string.h>

void super_print(const char x[])
{
    printf("| %-50s |\n", x);
    
}

int main()
{

    // const char *arr[] = {
    //     "Baron of Hell",
    //     "Demon",
    //     "Hellknight",
    //     "Cyberdemon",
    //     "Mancubus",
    //     "Revenant",
    //     "Doomimp",
    //     "Zombieman",
    //     "Shotguy",
    //     "Beholder",
    //     "Moloch",
    //     "Satyr",
    //     "Afrit",
    //     "Cybermastermind",
    //     "Nightmarecacodemon",
    // };
    const char x[] = "Hello there darkness my friend";
    // char x[100] = "";

    printf("%s\n", x);
    super_print(x);
    // strcat(x, arr[0]);
    // strcat(x, arr[1]);
    // printf("%s", x);
    return 0;
}
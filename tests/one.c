#include <stdio.h>
#include <string.h>

int main()
{

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

    char x[100] = "";
    strcat(x, arr[0]);
    strcat(x, arr[1]);
    printf("%s", x);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cool(void)
{
    int i;
    int k;

    i = 15;
    k = 0;
    // srand((unsigned)time(NULL));
    k = rand() % i;
    return k;
}

const char *x[] = {
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

int main()
{
    char *player;
    player = getenv("LOGNAME");
    for (int i = 0; i < 10; i++)
    {
        printf("%s was slaughtered by a %s.\n", player, x[cool()]);
    }
    return 0;
}
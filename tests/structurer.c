#include <stdio.h>
#include <string.h>

struct name
{
    char *name[20];
    int pages;
} first_book;

int main()
{
    *first_book.name = "Henory Willson";
    printf("Name: %s", *first_book.name);
    return 0;
}
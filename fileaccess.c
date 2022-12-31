#include <stdio.h>
#include <string.h>

int main()
{
    char arr[500][20];
    int x = 0;
    FILE *word_file = fopen("./high_fequency_wordlist_500.txt", "r");
    while (!feof(word_file))
    {
        fgets(arr[x], 20, word_file);
        arr[x][strcspn(arr[x], "\n")] = 0;
        printf(arr[x]);
        x++;
    }
    for (int i = 0; i < 500; i++)
    {
        printf("%s", arr[i]);
    }
}
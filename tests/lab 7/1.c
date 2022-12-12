/* Q1. Write a C struct code to display following output
Name: Henory Willson
NID NO: 2022222224555
Basic Pay: $20000
Home Country: BD
*/

#include <stdio.h>

struct Info
{
    char *name[20];
    unsigned long long nid;
    unsigned long int basic_pay;
    char *home_country[5];
} Person1;

int main()
{
    *Person1.name = "Henory Willson";
    Person1.nid = 2022222224555;
    Person1.basic_pay = 20000;
    *Person1.home_country = "BD";

    printf("Name: %s\n", *Person1.name);
    printf("NID NO: %lld\n", Person1.nid);
    printf("Basic Pay: $%lld\n", Person1.basic_pay);
    printf("Home Country: %s\n", *Person1.home_country);

    return 0;
}
/* 2008013
Q2. Write a C struct Code to display some attribute of a laptop and
SmartPhone1.
*/

#include <stdio.h>

struct SmartDevice
{
    char *name[20];
    unsigned long long price_in_usd;
    int year;
    int ram_gb;
    char *made_in[5];
};

void print_func(struct SmartDevice x)
{
    printf("Name: %s\n", *x.name);
    printf("NID NO: %lld\n", x.price_in_usd);
    printf("Basic Pay: $%d\n", x.year);
    printf("Ram Size: %dGB", x.ram_gb);
    printf("Home Country: %s\n", *x.made_in);
    printf("\n");
}
int main()
{
    struct SmartDevice SmartPhone1, Laptop1;
    *SmartPhone1.name = "SAMSUNG A20";
    SmartPhone1.price_in_usd = 300;
    SmartPhone1.year = 2020;
    SmartPhone1.ram_gb = 4;
    *SmartPhone1.made_in = "BD";

    *Laptop1.name = "SAMSUNG Alphabook 2";
    Laptop1.price_in_usd = 1200;
    Laptop1.year = 2022;
    Laptop1.ram_gb = 8;
    *Laptop1.made_in = "KR";

    print_func(Laptop1);
    print_func(SmartPhone1);
    return 0;
}
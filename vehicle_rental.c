#include <stdio.h>
#include <stdlib.h>

struct vehicle
{
    char name[20];
    int price_per_hour;
    int min_hours;
};

int calc_amt(struct vehicle v, int hours)
{
    int amt;
    if (hours < v.min_hours)
    {
        amt = v.price_per_hour * v.min_hours;
    }
    else
    {
        amt = v.price_per_hour * hours;
    }
    return amt;
}

int print_bill(struct vehicle v, int hours)
{
    printf("\n\n\n");
    printf("vehicle selected:%s\n", v.name);
    printf("hours of rental:%d\n", hours);
    printf("amount due:$%d\n", calc_amt(v, hours));
    printf("\n\n\n");
    return 0;
}
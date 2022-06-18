#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len = 0;
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
    printf("amount due:%d\n", calc_amt(v, hours));
    printf("\n\n\n");
    return 0;
}

void display_vehicles(struct vehicle v[])
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d for %s\n", i + 1, v[i].name);
    }
}

int add_vehicle(struct vehicle v[])
{
    v = realloc(v, (len + 1) * sizeof(struct vehicle));
    printf("enter vehicle name: ");
    scanf("%s", v[len].name);
    printf("enter price per hour: ");
    scanf("%d", &v[len].price_per_hour);
    printf("enter minimum hours: ");
    scanf("%d", &v[len].min_hours);
    len += 1;
    return 0;
}

int main()
{
    int initial_num_of_vehicles = 3;
    struct vehicle *vehicles = malloc(sizeof(vehicles[0]) * initial_num_of_vehicles);

    // intial data
    strcpy(vehicles[0].name, "car");
    vehicles[0].price_per_hour = 50;
    vehicles[0].min_hours = 4;
    strcpy(vehicles[1].name, "motocycle");
    vehicles[1].price_per_hour = 30;
    vehicles[1].min_hours = 3;
    strcpy(vehicles[2].name, "cycle");
    vehicles[2].price_per_hour = 10;
    vehicles[2].min_hours = 1;
    len = initial_num_of_vehicles;

    int choice = 0;
    while (choice != 3)
    {
        printf("\n\n\n");
        printf("enter choice 1: add vehicle\n");
        printf("enter choice 2: select vehicle\n");
        printf("enter choice 3: exit\n");
        printf("enter choice 4: display vehicles\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_vehicle(vehicles);
            break;
        case 2:
            display_vehicles(vehicles);
            int vehicle_choice;
            printf("enter vehicle choice: ");
            scanf("%d", &vehicle_choice);
            struct vehicle v = vehicles[vehicle_choice - 1];
            int hours;
            printf("enter hours of rental: ");
            scanf("%d", &hours);
            print_bill(v, hours);
            break;
        case 3:
            return 0;
        case 4:
            display_vehicles(vehicles);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
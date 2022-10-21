#include<stdio.h>

typedef int bool;

struct device
{
    int id;
    char name[20];
    char address[20];
    bool status;
    struct device *pnext;
};

void add_element(struct data **L, struct device data);
struct device get_data();

void main(void)
{

    struct device *L = NULL;
    struct device data = get_data();
    
    while(data.id < 0)
    {
        struct device data = get_data();
        add_element(&L,data);
    }

}

struct device get_data()
{
    struct device data;
    data.address[] = "185.23.6.5";
    data.id = 121;
    data.status = 1;
    data.name[] = "Scanner XYU";

    return data;
}

void add_element(struct data **L, struct device data)
{

    if(**L == NULL) //Es el primero.
    {
        *L = (struct device*)malloc(sizeof(struct device));

        (*L)->name = data.name;
        (*L)->address = data.address;
        (*L)->id = data.id
        (*L)->pnext = NULL;
    }
    else
    {
        *L = (struct device*)malloc(sizeof(struct device));

        (*L)->name = data.name;
        (*L)->address = data.address;
        (*L)->id = data.id
        (*L)->pnext = NULL;

    }
    
}

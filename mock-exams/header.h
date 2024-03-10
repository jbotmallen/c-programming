#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 50
#define MAX_ID 5
#define MAX_DIC 10

typedef char String[MAX_STRING];

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    String name;
    String brand;
    String type;
} ChocoDetails;

typedef struct
{
    char id[MAX_ID];
    ChocoDetails details;
    Date expiry;
    int quantity;
    float price;
} Choco;

typedef struct order
{
    Choco *chocos;
    struct order *next;
} *OrderList;

typedef OrderList OrderDic[MAX_DIC];

#include "header.h"

ChocoDetails newChocoDetails(String name, String brand, String type) {
    ChocoDetails details;
    strcpy(details.name, name);
    strcpy(details.brand, brand);
    strcpy(details.type, type);
    
    return details;
}

Date newDate(int day, int month, int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    
    return date;
}

Choco newChoco(String id, ChocoDetails details, Date expiry, int quantity, float price) {
    Choco choco;
    strcpy(choco.id, id);
    choco.details = details;
    choco.expiry = expiry;
    choco.quantity = quantity;
    choco.price = price;
    
    return choco;
}

void initializeOrderList(OrderList *L) {
    *L = NULL;
}

void initializeDicitonary(OrderDic D) {
    int i;

    for(i = 0; i < MAX_DIC; i++) {
        D[i] = NULL;
    }
}

void insertSortedList(OrderList *L, Choco *choco) {
    OrderList* trav;

    for(trav = L; *trav != NULL && strcmp((*trav)->chocos->id, choco->id) < 0; trav = &(*trav)->next) {}

    if(*trav == NULL || strcmp((*trav)->chocos->id, choco->id) != 0) {
        OrderList new = malloc(sizeof(struct order));
        if(new != NULL) {
            new->chocos = choco;
            new->next = *trav;
            *trav = new;
        }
    }
}

void populateListFromFile(OrderList *L, char *filename) {
    FILE *file = fopen(filename, "rb");
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        rewind(file);

        int numChocos = fileSize / sizeof(Choco);

        OrderList *trav;

        for(int i = 0; i < numChocos; i++) {
            Choco *choco = malloc(sizeof(Choco));
            if(choco != NULL) {
                fread(choco, sizeof(Choco), 1, file);
                insertSortedList(L, choco);
            }
        }

        fclose(file);
    }
}

void printOrderList(OrderList L) {
    printf("%-10s | %-25s | %-20s | %-5s | %-5s\n", "ID", "Name", "Brand", "Qty", "Price");
    printf("-----------------------------------------------------------------------------\n");
    for(OrderList trav = L; trav != NULL; trav = trav->next) {
        printf("%-10s | %-25s | %-20s | %5d | %5.2f\n", trav->chocos->id, trav->chocos->details.name, trav->chocos->details.brand, trav->chocos->quantity, trav->chocos->price);
    }
}

OrderDic* newOrderDic(char *filename) {
    FILE *file = fopen(filename, "r");
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        rewind(file);

        int numChocos = fileSize / sizeof(Choco);
    }
}

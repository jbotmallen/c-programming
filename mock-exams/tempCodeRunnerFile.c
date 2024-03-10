printf("Chocolates:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s %s %s %s %d %d %d %d %.2f\n", chocos[i].id, chocos[i].details.name, chocos[i].details.brand, chocos[i].details.type, chocos[i].expiry.day, chocos[i].expiry.month, chocos[i].expiry.year, chocos[i].quantity, chocos[i].price);
    }
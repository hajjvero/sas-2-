#include <stdio.h>
#include <string.h>
#include "menu/menu.h"
#include "util/display.h"

int main()
{
    // list of products
    ProducNode *producList = NULL;

    // Fill products manually and add to linked list
    for (int i = 0; i < 10; i++)
    {
        Product p;    // temp product
        sprintf(p.nom, "Product %d", i + 1);

        // Assign categories
        if (i < 3) 
            strcpy(p.categorie, "Electronics");
        else if (i < 6)
            strcpy(p.categorie, "Clothing");
        else if (i < 8)
            strcpy(p.categorie, "Books");
        else
            strcpy(p.categorie, "Furniture");

        p.prix = 50.0f + (i * 10); // just example prices
        p.stock = 5 + i;           // example stock
        sprintf(p.description, "This is the description for product %d", i + 1);

        // Same date for simplicity
        p.date.jour = 30;
        p.date.mois = 9;
        p.date.annee = 2025;

        // Add to linked list
        addProduc(&producList, p);
    }

    int choice;
    do
    {
        showMainMenu();

        displayByColor("Entrez votre choix: ", COLOR_MAGENTA);
        scanf("%d", &choice);

        handleMenuChoice(choice, &producList);
    } while (choice != 0);

    return 0;
}

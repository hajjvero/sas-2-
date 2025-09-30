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
        Product p; // temp product

        // Assign names and categories
        if (i < 3)
        {
            strcpy(p.categorie, "Electronics");
            if (i == 0)
                strcpy(p.nom, "Smartphone");
            else if (i == 1)
                strcpy(p.nom, "Laptop");
            else
                strcpy(p.nom, "Headphones");
        }
        else if (i < 6)
        {
            strcpy(p.categorie, "Clothing");
            if (i == 3)
                strcpy(p.nom, "T-Shirt");
            else if (i == 4)
                strcpy(p.nom, "Jeans");
            else
                strcpy(p.nom, "Jacket");
        }
        else if (i < 8)
        {
            strcpy(p.categorie, "Books");
            if (i == 6)
                strcpy(p.nom, "C Programming Guide");
            else
                strcpy(p.nom, "Data Structures Handbook");
        }
        else
        {
            strcpy(p.categorie, "Furniture");
            if (i == 8)
                strcpy(p.nom, "Office Chair");
            else
                strcpy(p.nom, "Wooden Desk");
        }

        p.prix = 50.0f + (i * 10); // just example prices
        p.stock = 5 + i;           // example stock

        sprintf(p.description, "This is the description for %s", p.nom);

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

#include <stdio.h>
#include "menu/menu.h"
#include "util/display.h"

int main()
{
    int choice;
    do
    {
        showMainMenu();

        displayByColor("Entrez votre choix: ", COLOR_MAGENTA);
        scanf("%d", &choice);

        handleMainChoice(choice);
    } while (choice != 0);

    return 0;
}

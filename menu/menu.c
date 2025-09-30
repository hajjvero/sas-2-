#include "stdio.h"
#include "string.h"
#include "menu.h"
#include "../util/display.h"
#include "input.h"

void menuTitle(char *name)
{
    // border top
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);

    int padding = (DISPLAY_WIDTH - strlen(name)) / 2;

    // center Tetx
    for (int i = 0; i < padding; i++)
        printf(" ");

    displayByColor(name, COLOR_YELLOW);
    printf("\n");

    // border bottom
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);
}

void menuSubTitle(char *title)
{
    printf("\n");
    int padding = (DISPLAY_WIDTH - strlen(title)) / 2;

    // center Tetx
    for (int i = 0; i < padding; i++)
        printf(" ");

    displayByColor(title, COLOR_YELLOW);
    printf("\n");

    // border bottom
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);
}

void showMainMenu()
{
    // clear console
    displayClear();

    // menu title
    menuTitle("Systeme de Gestion d'Achat Client");

    displayByColor(" [1]\tGestion du profil client\n", COLOR_GREEN);
    displayByColor(" [2]\tGestion du solde virtuel\n", COLOR_GREEN);
    displayByColor(" [3]\tConsultation des produits\n", COLOR_GREEN);
    displayByColor(" [4]\tEffectuer un achat\n", COLOR_GREEN);
    displayByColor(" [5]\tMes statistiques\n", COLOR_GREEN);
    displayByColor(" [0]\tQuitter l'application\n", COLOR_RED);
    printf("\n\n");
}

void handleMenuChoice(int choice, ProducNode **listProducts)
{
    switch (choice)
    {
    case 1:
        menuSubTitle("Gestion du profil client");

        break;
    case 2:
        menuSubTitle("Gestion du solde virtuel");

        break;
    case 3:
        // sectionof product
        menuSubTitle("Consultation des produits");

        // handle choice of operation of product
        int productChoice;
        do
        {
            showProducMenu();

            // handle input choice
            inputInteger("Entrez votre choix", &productChoice);

            handleMenuProductChoice(productChoice, &(*listProducts));
        } while (productChoice != 0);

        break;
    case 4:
        menuSubTitle("Effectuer un achat");

        break;
    case 5:
        menuSubTitle("Mes statistiques");

        break;
    case 0:
        displayClear();
        displayByColor("Merci d'utiliser notre application!\n", COLOR_BLUE);
        displayByColor("Au revoir!\n", COLOR_BLUE);
        break;
    default:
        displayByColor("\nChoix invalide!\n", COLOR_RED);
    }

    // this tis if not exit programe.
    if (choice != 0)
    {
        displayByColor("\nAppuyez sur Entree pour continuer ...\n", COLOR_CYAN);
        getchar(); // read last Entre from scanf.
        getchar(); // waiting user to Entre.F
    }
}
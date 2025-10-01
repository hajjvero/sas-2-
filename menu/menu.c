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

void handleMenuChoice(int choice, ProducNode **listProducts, Cleint **cleint)
{
    switch (choice)
    {
    case 1:
        menuSubTitle("Gestion du profil client");

        // handle choice of operation of cleint
        int cleintChoice;
        do
        {
            showCleintMenu(*cleint);

            // handle input choice
            inputInteger("Entrez votre choix", &cleintChoice);

            handleMenuCleintChoice(cleintChoice, &(*cleint));
        } while (cleintChoice != 0);
        break;
    case 2:
    {
        menuSubTitle("Gestion du solde virtuel");
        if ((*cleint) == NULL)
        {
            displayByColor("Pas de profil, ajoutez un profil s'il vous plait.\n", COLOR_RED);
        }
        else
        {
            int operationSoldChoice;
            do
            {
                showCleintMenuOfSolde();

                inputInteger("Entrez votre choix", &operationSoldChoice);

                switch (operationSoldChoice)
                {
                case 1:
                    menuSubTitle("Affichage du montant disponible");

                    // display Solde
                    displayByColor("Le montant disponible est : ", COLOR_CYAN);
                    printf("%.2f DH\n", (*cleint)->solde); // 2 decimal

                    break;
                case 2:
                    menuSubTitle("Depot d'argen");

                    float depot;
                    // add to solde
                    if (inputFloat("Saisie le montant de depot", &depot) == 1) // valide nomber
                    {
                        (*cleint)->solde += depot;

                        displayByColor("Alimentation du solde virtuel avec succes\n", COLOR_GREEN);
                    }
                    break;
                case 0:
                    displayByColor("Quitter\n", COLOR_RED);
                    break;
                default:
                    displayByColor("\nChoix invalide!\n", COLOR_RED);
                }
            } while (operationSoldChoice != 0);
        }
        break;
    }
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
        menuSubTitle("Effectuer un acheter");

        if ((*cleint) == NULL)
        {
            displayByColor("Pas de profil, ajoutez un profil s'il vous plait.\n", COLOR_RED);
        }
        else
        {
            int id;
            // selecte product by id
            inputInteger("Saisie Id de produit pour acheter", &id);

            ProducNode *producNode = findProduc(*listProducts, id);

            // not foun product.
            if (producNode == NULL)
            {
                displayByColor("Acune produit founder.\n", COLOR_RED);
            }
            else
            {
                infoProduct(&producNode->data); // display info of product
                int quantity;
                inputInteger("Saisie quantite de produit pour acheter", &quantity);

                // check stock
                if (quantity > producNode->data.stock)
                {
                    displayByColor("Stock non disponible.\n", COLOR_RED);
                    printf("Le stock disponible est : %d\n", producNode->data.stock);
                }
                else
                {
                    // check sold
                    if ((*cleint)->solde < (quantity * producNode->data.prix))
                    {
                        displayByColor("Solde insuffisant.\n", COLOR_RED);
                    }
                    else
                    {
                        // cofirmation from user
                        int userConfirm;

                        displayByColor(" [1]\tValider achat\n", COLOR_GREEN);
                        displayByColor(" [0]\tAnuller\n", COLOR_RED);

                        inputInteger("Confirmer l'achat s'il vous plait", &userConfirm);

                        if (userConfirm == 1)
                        {
                            // decrement quantity and sold
                            (*cleint)->solde -= quantity * producNode->data.prix;

                            producNode->data.stock -= quantity;
                            producNode->data.quantityConsumed += quantity;

                            displayByColor("\nTransaction d'achat reussie.\n", COLOR_GREEN);
                        }
                        else
                        {
                            displayByColor("\nAnuller l'achat.\n", COLOR_YELLOW);
                        }
                    }
                }
            }
        }
        break;
    case 5:
        menuSubTitle("Mes statistiques");
        int countProduct = 0, totalQuantity = 0;
        float totalPrice = 0;
        // display list of products acheter.
        ProducNode *temp = *listProducts;
        while (temp != NULL)
        {
            if (temp->data.quantityConsumed > 0) // product solder
            {
                printf("%d - %s - Quantite : %d\n", ++countProduct, temp->data.nom, temp->data.quantityConsumed);
                totalPrice += temp->data.quantityConsumed * temp->data.prix;
                totalQuantity += temp->data.quantityConsumed;
            }

            temp = temp->next;
        }

        if (countProduct > 0)
        {
            printLine("=", DISPLAY_WIDTH / 2, COLOR_BLUE);
            displayByColor("Nomber des produit : ", COLOR_CYAN);
            printf("%d\n", countProduct);

            displayByColor("Total : ", COLOR_CYAN);
            printf("%.2f DH\n", totalPrice);

            displayByColor("Total les quantites : ", COLOR_CYAN);
            printf("%d\n", totalQuantity);
        } else {
            displayByColor("\nAucun produits acheter.\n", COLOR_YELLOW);
        }
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
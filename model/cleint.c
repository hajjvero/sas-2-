#include "cleint.h"
#include "stdio.h"
#include "../util/display.h"
#include "stdlib.h"
#include "string.h"
#include "../util/input.h"

// Function to menu of cleint
void showCleintMenu(Cleint *cleint)
{
    printf("\n");
    if (cleint == NULL)
    {
        displayByColor(" [1]\tCreation de profil\n", COLOR_GREEN);
    }
    else
    {
        displayByColor(" [1]\tModification du profil\n", COLOR_GREEN);
    }

    displayByColor(" [2]\tConsultation du profil\n", COLOR_GREEN);
    displayByColor(" [0]\tQuitter\n", COLOR_RED);
    printf("\n\n");
}

void cleintMenuSubTitle(char *title)
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

// Function to handle menu cleint
void handleMenuCleintChoice(int choice, Cleint **cleint)
{
    switch (choice)
    {
    case 1:
        // no cleint
        if (*cleint == NULL)
        {
            cleintMenuSubTitle("Creation de profil");

            *cleint = (Cleint *)malloc(sizeof(Cleint));

            // form of cleint
            inputText("Saisie nom", (*cleint)->nom);

            inputText("Saisie prenom", (*cleint)->prenom);

            // generate email from nom and prenom
            sprintf((*cleint)->email, "%s.%s@email.com", (*cleint)->nom, (*cleint)->prenom);

            // default value of solde
            (*cleint)->solde = 5000;

            (*cleint)->id = 1;

            displayByColor("Ajouter avec succes.\n", COLOR_GREEN);
        }
        else
        {
            // exist cleint
            cleintMenuSubTitle("Modification du profil");

            infoCleint(*cleint);

            // TODO: edit

            int propertyCleintChoice;
            do
            {
                displayByColor(" [1]\tNom\n", COLOR_GREEN);
                displayByColor(" [2]\tPrenom\n", COLOR_GREEN);
                displayByColor(" [0]\tQuitter\n", COLOR_RED);

                inputInteger("Entre le propriete de modifier", &propertyCleintChoice);

                switch (propertyCleintChoice)
                {
                case 1:
                    // Nom
                    inputText("Saisie nom", (*cleint)->nom);

                    displayByColor("Modifier nom avec succes.\n", COLOR_GREEN);
                    break;
                case 2:
                    // Prenom
                    inputText("Saisie prenom", (*cleint)->prenom);
                    displayByColor("Modifier prenom avec succes.\n", COLOR_GREEN);
                    break;
                case 0:
                    displayByColor("Quitter\n", COLOR_RED);
                    break;
                default:
                    displayByColor("\nChoix invalide!\n", COLOR_RED);
                    break;
                }
                /* code */
            } while (propertyCleintChoice != 0);

            // new generate email from nom and prenom
            sprintf((*cleint)->email, "%s.%s@email.com", (*cleint)->nom, (*cleint)->prenom);

            displayByColor("Modifier profil avec succes.\n", COLOR_GREEN);
        }
        break;
    case 2:
        cleintMenuSubTitle("Consultation du profil");

        infoCleint(*cleint);
        break;
    case 0:
        displayByColor("Quitter", COLOR_RED);
        break;
    default:
        displayByColor("\nChoix invalide!\n", COLOR_RED);
    }
}

// Function to display information of cleint
void infoCleint(Cleint *cleint)
{
    if (cleint == NULL)
    {
        displayByColor("Aucun profile a afficher.\n", COLOR_RED);
        return;
    }

    printf("\nID       : %d\n", cleint->id);
    printf("Nom      : %s\n", cleint->nom);
    printf("Prenom   : %s\n", cleint->prenom);
    printf("Email    : %s\n", cleint->email);
    printf("Solde    : %.2f DH\n", cleint->solde); // 2 decimal
    printLine("=", DISPLAY_WIDTH / 2, COLOR_CYAN);
}
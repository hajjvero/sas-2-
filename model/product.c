#include "product.h"
#include "../util/display.h"
#include "stdio.h"
#include "string.h"
#include "input.h"
#include "stdlib.h"
#include "../menu/menu.h"

// Function to display list
void allProducts(ProducNode *head)
{
    ProducNode *temp = head;

    if (temp == NULL)
    {
        displayByColor("Liste vide.\n", COLOR_BLUE);
        return;
    }

    while (temp != NULL)
    {
        infoProduct(&temp->data);
        temp = temp->next;
    }
}

// Function to Add new
void addProduc(ProducNode **head, Product product)
{
    // create Node of aeroport.
    ProducNode *node = (ProducNode *)malloc(sizeof(ProducNode));

    node->data = product;
    node->next = NULL;

    // check if the head is empty.
    if (*head == NULL)
    {
        // firt element
        node->data.id = 1;

        *head = node;
    }
    else
    {
        // start from head of node.
        ProducNode *temp = *head;

        // go to last node.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // set to last id + 1
        node->data.id = temp->data.id + 1;

        // add new node to last node.
        temp->next = node;
    }

    displayByColor("Ajouter avec succes.", COLOR_GREEN);
}

// Function to update
void editProduc(ProducNode *head, int id, Product product)
{
    ProducNode *node = findProduc(head, id);

    if (node == NULL)
    {
        displayByColor("\nAucun produit trouve", COLOR_RED);
    }
    else
    {
        // Update data by new product
        node->data = product;
    }

    displayByColor("Modification avec succes.", COLOR_GREEN);
}

// Function to find node by id (liner Search)
ProducNode *findProduc(ProducNode *head, int id)
{
    // srt to head of list
    ProducNode *temp = head;
    while (temp->next != NULL) // go to find from start to end
    {
        if (temp->data.id == id)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Function to find  node by nom (liner Search)
ProducNode *findProducByNom(ProducNode *head, char *nom)
{
    // srt to head of list
    ProducNode *temp = head;
    while (temp->next != NULL) // go to find from start to end
    {
        //  compar without uupper o lower case
        if (strcasecmp(temp->data.nom, nom) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Function to find  node by categorie (liner Search)
ProducNode *findProducByCategorie(ProducNode *head, char *categorie)
{
    // srt to head of list
    ProducNode *temp = head;
    while (temp->next != NULL) // go to find from start to end
    {
        //  compar without uupper o lower case
        if (strcasecmp(temp->data.categorie, categorie) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Function to display information
void infoProduct(Product *p)
{
    printf("\nID           : %d\n", p->id);
    printf("Nom          : %s\n", p->nom);
    printf("Categorie    : %s\n", p->categorie);
    printf("Prix         : %.2f\n", p->prix); // 2 decimals
    printf("Stock        : %d\n", p->stock);
    printf("Description  : %s\n", p->description);
    printf("Date Created : %02d/%02d/%04d\n", p->date.jour, p->date.mois, p->date.annee);
    printLine("=", DISPLAY_WIDTH / 2, COLOR_CYAN);
}

// Function to sort data by price (using bubble sort algorithm).
// and use order asc or desc
void sortByPrix(ProducNode *head)
{
    int choice; // 0: asc  1: desc

    do
    {
        displayByColor("[0]\tCroissant\n", COLOR_YELLOW);   // asc
        displayByColor("[1]\tDécroissant\n", COLOR_YELLOW); // desc

        // input int
        inputInteger("Entrer order", &choice);

        if (choice != 0 || choice != 1)
        {
            displayByColor("\nChoix invalide!\n", COLOR_RED);
        }
    } while (choice != 0 || choice != 1); // select invalid choice.

    // empty list
    if (head == NULL)
    {
        displayByColor("Liste vide.\n", COLOR_BLUE);
        return;
    }

    ProducNode *cuurrent; // current pointer, set to first node in list.
    int swapped;          // varible to exit loop if is sorted.

    do
    {
        swapped = 0;     // set to false
        cuurrent = head; // strat from head of list

        while (cuurrent->next != NULL) // got from start to last element
        {
            // check if asc or desc
            if ((choice == 1 && cuurrent->data.prix < cuurrent->next->data.prix) || (choice == 0 && cuurrent->data.prix > cuurrent->next->data.prix))
            {
                // swap data
                Product temp = cuurrent->data;
                cuurrent->data = cuurrent->next->data;
                cuurrent->next->data = temp;
                swapped = 1; // set to true
            }

            // ro to next node
            cuurrent = cuurrent->next;
        }
    } while (swapped); // if not swap data , list is sorted.

    displayByColor("Trier avec succes", COLOR_GREEN);

    allProducts(head);
}

// Function to sort data by nom (using bubble sort algorithm).
// and use order asc or desc
void sortByNom(ProducNode *head)
{
    int choice; // 0: asc  1: desc

    do
    {
        displayByColor("[0]\tCroissant\n", COLOR_YELLOW);   // asc
        displayByColor("[1]\tDécroissant\n", COLOR_YELLOW); // desc

        // input int
        inputInteger("Entrer order", &choice);

        if (choice != 0 || choice != 1)
        {
            displayByColor("\nChoix invalide!\n", COLOR_RED);
        }
    } while (choice != 0 || choice != 1); // select invalid choice.

    // empty list
    if (head == NULL)
    {
        displayByColor("Liste vide.\n", COLOR_BLUE);
        return;
    }

    ProducNode *cuurrent; // current pointer, set to first node in list.
    int swapped;          // varible to exit loop if is sorted.

    do
    {
        swapped = 0;     // set to false
        cuurrent = head; // strat from head of list

        while (cuurrent->next != NULL) // got from start to last element
        {
            // check if asc or desc
            if ((choice == 1 && strcasecmp(cuurrent->data.nom, cuurrent->next->data.nom) < 0) || (choice == 0 && strcasecmp(cuurrent->data.nom, cuurrent->next->data.nom) > 0))
            {
                // swap data
                Product temp = cuurrent->data;
                cuurrent->data = cuurrent->next->data;
                cuurrent->next->data = temp;
                swapped = 1; // set to true
            }

            // ro to next node
            cuurrent = cuurrent->next;
        }
    } while (swapped); // if not swap data , list is sorted.

    displayByColor("Trier avec succes", COLOR_GREEN);

    allProducts(head);
}

// Function to display form of search.
void searchProduct(ProducNode *head)
{

}

// Function to menu of product
void showProducMenu()
{
    displayByColor(" [1]\tAffichage catalogue\n", COLOR_GREEN);
    displayByColor(" [2]\tRecherche produits\n", COLOR_GREEN);
    displayByColor(" [3]\tTri des produits\n", COLOR_GREEN);
    displayByColor(" [0]\tQuitter\n", COLOR_RED);
    printf("\n\n");
}

void handleMenuProductChoice(int choice, ProducNode **head) {
    switch (choice)
    {
    case 1:
        menuSubTitle("Affichage catalogue");
        allProducts(*head);
        break;
    case 2:
        menuSubTitle("Recherche produits");
        searchProduct(*head);
        break;
    case 3:
        menuSubTitle("Tri des produits");
        // sort
        break;
    case 0:
        displayByColor("Quitter",COLOR_RED);
        break;    
    default:
        displayByColor("\nChoix invalide!\n", COLOR_RED);
    }
}
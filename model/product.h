#ifndef PRODUCT_H
#define PRODUCT_H
#include "data.h"

// Function to display list
void allProducts(ProducNode *head);

// Function to Add new
void addProduc(ProducNode **head, Product product);

// Function to update
void editProduc(ProducNode *head, int id, Product product);

// Function to find node by id (liner Search)
ProducNode *findProduc(ProducNode *head, int id);

// Function to find  node by nom (liner Search)
ProducNode *findProducByNom(ProducNode *head, char *nom);

// Function to find  node by categorie (liner Search)
ProducNode *findProducByCategorie(ProducNode *head, char *categorie);

// Function to display information
void infoProduct(Product *product);

// Function to sort data by price (using bubble sort algorithm).
// and use order asc or desc
void sortByPrix(ProducNode *head);

// Function to sort data by nom (using bubble sort algorithm).
// and use order asc or desc
void sortByNom(ProducNode *head);

// Function to display form of search.
void searchAeroport(ProducNode* head);

// Function to menu of product
void showProducMenu();

// Function to handle choice of user in section of products
void handleMenuProductChoice(int choice, ProducNode **head);
#endif
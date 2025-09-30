#ifndef MENU_H
#define MENU_H
#include "../model/product.h"

// Function to display title of application
void menuTitle(char* name);

// Funtion to display choice to user
void showMainMenu();

// dosplay sub title with border buttom
void menuSubTitle(char *title);

// Function to tretment choice of user.
void handleMenuChoice(int choice, ProducNode **listProducts);

#endif
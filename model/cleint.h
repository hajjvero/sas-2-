#ifndef CLEINT_H
#define CLEINT_H
#include "data.h"

// Function to menu of cleint
void showCleintMenu(Cleint *cleint);

// Function to handle menu cleint
void handleMenuCleintChoice(int choice, Cleint **cleint);

// Function to display information of cleint
void infoCleint(Cleint *cleint);
#endif
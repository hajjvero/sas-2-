#include "stdio.h"
#include "input.h"
#include "string.h"
#include "display.h"

int inputText(char* label, char* text) {
    printf("\n%s : ", label);

    // The space before % handles any leading whitespace.
    // The %255[^\n] reads up to 255 characters.
    if (scanf(" %254[^\n]", text) != 1)
    {
        return 0;
    }

    // success input
    return 1;
}

int inputInteger(char* label, int* value) {
    printf("%s : ", label);

     if (scanf("%d",  value) != 1)
    {
        displayByColor("Error: Invalid integer input!\n", COLOR_RED);

        return 0;
    }

     // success input
    return 1;
}

int inputDouble(const char* label, double* value) {
    printf("%s : ", label);

     if (scanf("%f",  value) != 1)
    {
        displayByColor("Error: Invalid double input!\n", COLOR_RED);

        return 0;
    }

     // success input
    return 1;
}

int inputFloat(const char* label, float* value) {
    printf("%s : ", label);

     if (scanf("%f",  value) != 1)
    {
        displayByColor("Error: Invalid double input!\n", COLOR_RED);

        return 0;
    }

     // success input
    return 1;
}

int inputChar(const char* label, char* value) {
    printf("%s : ", label);

     if (scanf("%c", value) != 1)
    {
        displayByColor("Error: Invalid char input!\n", COLOR_RED);

        return 0;
    }

     // success input
    return 1;
}
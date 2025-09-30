#include "display.h"
#include <stdlib.h>
#include <stdio.h>

void displayClear() {
    system("cls");
}

void displayByColor(char *content, int colorCode) {
    // Build and apply ANSI escape sequence
    printf("\x1b[%dm%s\x1b[0m", colorCode, content);
}

void printLine(char* content, int length, int colorCode) {
    for(int i = 0; i < length; i++) {
        displayByColor(content, colorCode);
    }
    printf("\n");
}

#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_WIDTH 80 // With of display app 

// color codes
#define COLOR_BLACK   30
#define COLOR_RED     31
#define COLOR_GREEN   32
#define COLOR_YELLOW  33
#define COLOR_BLUE    34
#define COLOR_MAGENTA 35
#define COLOR_CYAN    36

// Function to clear console.
void displayClear();

// Function to display text with color
void displayByColor(char* content, int colorCode);

// Function to print a horizontal line
void printLine(char* content, int length, int colorCode);
#endif
#ifndef INPUT_H
#define INPUT_H

// Reads a text string from user
int inputText(char* label, char* text);

// Reads an integer from user
int inputInteger(char* label, int* value);

// Reads a double from user
int inputDouble(const char* label, double* value);

// Reads a float from user
int inputFloat(const char* label, float* value);

// Reads a character from user
int inputChar(const char* label, char* value);
#endif
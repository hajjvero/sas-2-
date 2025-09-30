#ifndef INPUT_H
#define INPUT_H

/**
 * Reads a text string from user
 * @param label: The prompt message to display
 * @param text: Pointer to char array to store the input
 * @return: 1 if successful, 0 if failed
 */
int inputText(char* label, char* text);

/**
 * Reads an integer from user
 * @param label: The prompt message to display
 * @param value: Pointer to int variable to store the input
 * @return: 1 if successful, 0 if failed
 */
int inputInteger(char* label, int* value);

/**
 * Reads a double/float from user
 * @param label: The prompt message to display
 * @param value: Pointer to double variable to store the input
 * @return: 1 if successful, 0 if failed
 */
int inputDouble(const char* label, double* value);

/**
 * Reads a character from user
 * @param label: The prompt message to display
 * @param value: Pointer to char variable to store the input
 * @return: 1 if successful, 0 if failed
 */
int inputChar(const char* label, char* value);
#endif
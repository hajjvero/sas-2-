#include "ctype.h"
#include "string.h"
#include "helper.h"

// Function to convert string to lower case
void stringToLowerCase(char *string, char *dest)
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        dest[i] = tolower(string[i]);
    }
}
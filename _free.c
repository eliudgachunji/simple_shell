#include "simple.h"

/**
 * _free - frees a double pointer
 * @string: pointer to array to free in heap memory
 * Return: void
 */

void _free(char **string)

{

size_t k = 0;

if (string == NULL)
return;

while (string[k])

{

free(string[k]);
k++;

}

free(string);
}

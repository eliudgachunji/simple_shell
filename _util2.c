#include "simple.h"

/**
 * _puts - will print a string as is
 * @str: string to print
 * Return: number of characters printed
 */

int _puts(char *str)

{

int j;

for (j = 0; str[j] != '\0'; j++)
_putchar(str[j]);

return (j);

}

/**
 * _strcmp - will compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: the result of the comparison
 */

int _strcmp(char *s1, char *s2)

{

int j;
int n = 0;

for (j = 0; !n; j++)

{

n = *(s1 + j) - *(s2 + j);

if (*(s1 + j) == '\0' && *(s2 + j) == '\0')
break;

}

return (n);
}

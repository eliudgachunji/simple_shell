#include "simple.h"

/**
 * tokens - split the string into tokens
 * @string: input string saved in getline
 * Return: pointer to array of tokens
 */

char **tokens(char *string)

{

char **savingtok = NULL;
char *token = _strdup(string);
int j = 0, ntok = 0;
char *tmp = NULL;

tmp = string;
tmp = strtok(tmp, " \n\t");

while (tmp != NULL)

{
ntok++;

tmp = strtok(NULL, " \n\t");

}

savingtok = (char **) malloc((ntok * sizeof(char *) + 1));
token = strtok(token, " \n\t");

while (token != NULL)

{

savingtok[j] = _strdup(token);
j++;

token = strtok(NULL, " \n\t");

}

savingtok[ntok + 1] = '\0';
free(token);

return (savingtok);
}

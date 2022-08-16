#include "simple.h"

/**
 * builtin_exit - exits the shell
 * @args: arguments
 * Return: nothing
 */

int builtin_exit(char **args, env_t *envi)

{

free(args[0]);
free(args);

if (envi != NULL)
free_env(envi);
exit(0);

}


/**
 * builtin_env - print the environment
 * @envi: environment linked list
 * Return: status
 */

int builtin_env(char **args, env_t *envi)

{

if (*args == NULL || envi == NULL)
return (98);

print_env(envi);

return(0);
}

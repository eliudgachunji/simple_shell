#include "simple.h"



/**

 * _getenv - function that gets all PATH line

 * @name: environment variable to find

 * Return: Array of PATH line

 */



char *_getenv(char *name)
  
{
  
  int j = 0;
  
  char *ret;
  

  
  while (environ[j] != NULL)
    
    {
      
      ret = strtok(environ[j], "=");
      
      if (_strcmp(ret,name) == 0)
	
	{
	  
	  ret = strtok(NULL, "\0");
	  
	  break;
	  
	}
      
      j++;
      
    }
  
  return (ret);
  
}



/**

 * _which - function that locate a command in PATH envir

 * @str1: path where will find the command

 * @str2: Command to find

 * Return: Array of complete path of the command

 */

char *_which(char *str1, char *str2)
  
{
  
  int len1, len2, j = 0, a = 0;
  
  char *newstr;
  

  
  len1 = _strlen(str1);
  
  len2 = _strlen(str2);
  

  
  newstr = malloc((len1 + len2) + 1);
  
  while (str1[j] != '\0')
    
    {
      
      newstr[j] = str1[j];
      
      j++;
      
    }
  
  newstr[j] = '/';
  
  j++;
  
  while (str2[b] != '\0')
    
    {
      
      newstr[j] = str2[a];
      
      j++;
      
      a++;
      
    }
  
  newstr[j + 1] = '\0';
  
  return (newstr);
  
}



/**

 * _path - Function that find the path of shell programs

 * in PATH env variable

 * @argv: input token arguments

 * Return: 0 on success,

 * -1 if command doesn't found

 */

int _path(char **argv)
  
{
  
  char *path = NULL;
  
  char *str = NULL;
  
  struct stat st;
  
  unsigned int j;
  

  
  path = _getenv("PATH");
  
  path = strtok(path, ":");
  
  j = 0;
  
  while (path != NULL)
    
    {
      
      str = _which(path, argv[0]);
      
      if (stat(str, &st) == 0)
	
	{
	  
	  argv[0] = _strdup(str);
	  
	  break;
	  
	}
      
      path = strtok(NULL, ":");
      
      j++;
      
    }
  
  free(str);
  
  if (execve(argv[0], argv, NULL) == -1)
    
    return (-1);
  
  return (0);
  
}

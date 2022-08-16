#include "simple.h"

/**
 * _printenv - print enviroment

 */

void _printenv(void)
  
{
  
  int j = 0;
  

  
  while (environ[j] != NULL)
    
    {
      
      write(1, environ[j], _strlen(environ[j]));
      
      write(1, "\n", 1);
      
      j++;
      
    }
  
}

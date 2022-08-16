#include "simple.h"



/**

 * _strdup - will malloc a space in memory and copy a string to it

 * @str: string to copy

 *

 * Return: a pointer pointing to the created string

 */

char *_strdup(char *str)
  
{
  
  int j = 1, k = 0;
  
  char *cpy;
  

  
  if (str == NULL)
    
    return (NULL);
  

  
  while (*(str + j != '\0')
	 
	 j++;
	 

	 
	 cpy = malloc((sizeof(char) * j) + 1);
	 
	 if (cpy == NULL)
	   
	   return (NULL);
	 
	 do {
	   
	   *(cpy + k) = *(str);
	   
	   k++;
	   
	   str++;
	   
	 } while (*(str - 1) != '\0');
	 

	 
	 return (cpy);
	 
	 }
    

    
  /**

   * _realloc - will reallocate space in memory

   * @ptr: memory to be reallocated

   * @old_size: size in bytes of original memory

   * @new_size: size in bytes to be allocated

   *

   * Return: pointer to allocated space on success, NULL on failure,

   * ptr on no change

   */
    
  void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
    
  {
    
    void *res;
    
    char *accessin, *accessout;
    
    unsigned int k;
    

    
    if (!new_size && ptr)
      
      {
	
	free(ptr);
	
	return (NULL);
	
      }
    
    if (new_size == old_size)
      
      return (ptr);
    

    
    res = malloc(new_size);
    
    if (!res)
      
      return (NULL);
    
    accessin = ptr;
    
    accessout = res;
    

    
    if (ptr)
      
      {
	
	for (k = 0; k < old_size && k < new_size; k++)
	  
	  *(accessout + k) = *(accessin + k);
	

	
	free(ptr);
	
      }
    

    
    return (res);
    
  }
  

  
  /**

   * _putchar - writes the character c to stdout

   * @c: The character to print

   *

   * Return: On success 1.

   * On error, -1 is returned, and errno is set appropriately.

   */
  
  int _putchar(char c)
    
  {
    
    return (write(1, &c, 1));
    
  }
  

  
  /**

   * rev_string - will reverse a string

   * @s: the string to be reversed

   *

   * Return: doesn't

   */
  
  void rev_string(char *s)
    
  {
    
    char buf;
    
    int k;
    
    int len;
    

    
    for (len = 0; s[len] != '\0'; len++)
      
      continue;
    

    
    len--;
    

    
    for (k = 0; k <= len ; k++)
      
      {
	
	buf = s[len];
	
	s[len] = s[k];
	
	s[k] = buf;
	
	len--;
	
      }
    
  }
  

  
  /**

   * _strlen - will find the length of the string

   * @s: a pointer to the string

   *

   * Return: the length of the string

   */
  
  int _strlen(char *s)
    
  {
    
    int k = 0;
    

    
    if (*s)
      
      {
	
	while (*(s + k) != '\0')
	  
	  k++;
	
      }
    

    
    return (k);
    
  }

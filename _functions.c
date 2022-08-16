#include "simple.h"

/**

 * *_strcmp - compare two strings

 * @s1: string 1

 * @s2: string 2

 * Return: void

 */

int _strcmp(char *s1, char *s2)
  
{
  
  int x = 0;
  

  
  while (s1[x] == s2[x])
    
    {
      
      if (s1[x] == '\0' && s2[x] == '\0')
	
	{
	  
	  break;
	  
	}
      
      x++;
      
    }
  
  return (s1[x] - s2[x]);
  
}

/**

 * *_strcpy - copies string pointed to srd

 * @dest: dest array

 * @src: src array

 * Return: pointer to dest

 */

char *_strcpy(char *dest, char *src)
  
{
  
  int x;
  

  
  for (x = 0; src[x] != '\0'; x++)
    
    {
      
      dest[x] = src[x];
      
    }
  
  dest[x] = '\0';
  
  return (dest);
  
}

/**

 * _strlen - swap value of two intergers

 * @s: string

 * Return: void

 */

int _strlen(char *s)
  
{
  
  int c = 0;
  

  
  while (s[c] != '\0')
    
    {
      
      c++;
      
    }
  
  return (c);
  
}

/**

 * _strdup - duplicates a string

 * @str: string input

 * Return: duplicated string

 */

char *_strdup(char *str)
  
{
  
  char *a;
  

  
  if (str == '\0')
    
    {
      
      return (NULL);
      
    }
  
  a = malloc(_strlen(str) * sizeof(char) + 1);
  
  if (a == '\0')
    
    {
      
      return (NULL);
      
    }
  
  _strcpy(a, str);
  
  return (a);
  
}

/**

 * _strcat- function that concatenates two strings.

 *

 * @dest: pointer to destination char

 * @src: pointer to source char

 * Return: char

 */

char *_strcat(char *dest, char *src)
  
{
  
  unsigned int x = 0;
  
  unsigned int y = 0;
  

  
  while (*(dest + x) != '\0')
    
    i++;
  
  while (*(src + y) != '\0')
    
    {
      
      *(dest + x) = *(src + y);
      
      x++;
      
      y++;
      
    }
  
  return (dest);
  
}

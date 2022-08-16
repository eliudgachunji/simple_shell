#include "simple.h"



/**

 * genv - will obtain the environment and assign it to a linked list

 *

 * Return: pointer to head of the list

 */

env_t *genv(void)
  
{
  
  env_t *envi = NULL;
  
  int i = 0;
  

  
  for (i = 0; environ[i] != NULL; i++)
    
    envt_node_end(&envi, environ[i]);
  

  
  return (envi);
  
}



/**

 * gval - will get a value within an env_t linked list

 * @head: head of environment list

 * @title: name of environmental variable

 *

 * Return: specified value within the environment

 */

char *gval(env_t *head, char *title)
  
{
  
  char *val;
  

  
  while (head != NULL)
    
    {
      
      if (_strcmp(head->title, title) == 0)
	
	val = strdup(head->value);
      
      head = head->next;
      
    }
  

  
  return (val);
  
}



/**

 * envt_node_end - will add a node to the end of a env_t list

 * @head: the head of the list, NULL is list doesn't exist yet

 * @str: string to enter as a memeber of the list

 *

 * Return: pointer to the head of the list

 */

env_t *envt_node_end(env_t **head, const char *str)
  
{
  
  env_t *newh, *pos;
  
  char *st = NULL, *s = NULL, *s2 = NULL;
  

  
  st = strdup(str);
  
  if (st == NULL)
    
    return (NULL);
  
  s = strtok(st, "="), s2 = strtok(NULL, "\0");
  
  pos = *head;
  
  newh = malloc(sizeof(env_t));
  
  if (newh == NULL)
    
    {
      
      free(st);
      
      return (NULL);
      
    }
  
  if (s != NULL)
    
    {
      
      newh->title = strdup(s);
      
      if (newh->title == NULL)
	
	{
	  
	  free(st), free(newh);
	  
	  return (NULL);
	  
	}
      
      if (s2 != NULL)
	
	{
	  
	  newh->value = strdup(s2);
	  
	  if (newh->value == NULL)
	    
	    free(st), free(newh->title), free(newh);
	  
	}
      
    }
  
  if (*head != NULL)
    
    {
      
      while (pos != NULL && pos->next != NULL)
	
	pos = pos->next;
      
      pos->next = newh;
      
    }
  
  else
    
    *head = newh;
  
  newh->next = NULL;
  
  free(st);
  
  return (*head);
  
}





/**

 * free_env - will free an env_t list

 * @head: head of the list

 *

 *Return: nothing

 */

void free_env(env_t *head)
  
{
  
  env_t *hold;
  

  
  while (head != NULL)
    
    {
      
      free(head->title);
      
      free(head->value);
      
      hold = head->next;
      
      free(head);
      
      head = hold;
      
    }
  
}



/**

 * print_env - will print the environment

 * @envi - linked list the environment is stored in

 *

 * Return: nothing

 */

void print_env(env_t *envi)
  
{
  
  while (envi != NULL)
    
    {
      
      if (envi->title != NULL)
	
	{
	  
	  _puts(envi->title);
	  
	  if (envi->value)
	    
	    {
	      
	      _putchar('=');
	      
	      _puts(envi->value);
	      
	    }
	  
	  _putchar('\n');
	  
	}
      
      envi = envi->next;
      
    }
  
}

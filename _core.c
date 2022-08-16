#include "simple.h"



/**

 * main - main for the simple shell program

 *

 * Return: nothing

 */

int main(void)
  
{
  
  int ret;
  

  
  ret = shellcore();
  

  
  return (ret);
  
}



/**

 * shellcore - is the core loop of the shell

 *

 * Return: shell ending status

 */

int shellcore(void)
  
{
  
  char *line = NULL, *prompt = "($) ";
  
  char **args = NULL;
  
  int stat = 0, cont[] = {1, 0}, i = 0;
  
  size_t len = 0;
  
  env_t *envi = NULL;
  

  
  envi = genv();
  
  /*signal(SIGQUIT, SIG_IGN);*/
  
  while (cont[0])
    
    {
      
      if (isatty(STDIN_FILENO))
	
	_puts(prompt);
      
      /*printf("ATTEMPT #%i\n", i);*/
      
      /*gets input*/
      
      stat = getline(&line, &len, stdin);
      
      if (stat < 0)
	
	{
	  
	  free_env(envi);
	  
	  envi = NULL;
	  
	  free(line);
	  
	  cont[0] = 0;
	  
	}
      
      else
	
	{
	  
	  /*segments input*/
	  
	  args = linecut(line);
	  
	  /*func to take care of builtins*/
	  
	  stat = com_execute(args, envi);
	  
	  i++;
	  
	  if (line != NULL)
	    
	    free(line);
	  

	  
	  if (args != NULL)
	    
	    free(args);
	  
	  args = NULL;
	  
	  line = NULL;
	  
	}
      
    }
  
  if (envi != NULL)
    
    free_env(envi);
  
  return (stat);
  
}



/**

 * linecut - will cut a line into different arguments

 * @line: line to be cut into arguments

 *

 * Return: two dimensional array containing arguments

 */

char **linecut(char *line)
  
{
  
  char **args = NULL;
  
  int i = 0, size = 1;
  

  
  do {
    
    if (args == NULL)
      
      {
	
	args = malloc(sizeof(char **) * size);
	
	if (args == NULL)
	  
	  return (NULL);
	
	args[i] = strtok(line, " \n\t");
	
      }
    
    else
      
      {
	
	args = _realloc(args, sizeof(char **) * (size - 1), sizeof(char **) * size);
	
	if (args == NULL)
	  
	  return (NULL);
	
	args[i] = strtok(NULL, " \n\t");
	
      }
    
    i++, size++;
    
  } while (args[i - 1] != NULL);
  

  
  return (args);
  
}



/*

 *   int line_read(void)

 *   {

 *

 *   }

 *

 *  char **_strtok(char *imt)

 *   {

 *

 *   }

 */



/**

 * blt_execute - will execute builtin functions

 * @args: pointer array containing arguments

 *

 * Return: status number of called function, -1 on failure

 */

int blt_execute(char **args, env_t *envi)
  
{
  
  int i = 0, stat = -1;
  
  builtin_t builts[] = {
			
			{"exit", builtin_exit},
			
			{"env", builtin_env},
			
			{NULL, NULL},
			
  };
  

  
  while (builts[i].builtin != NULL)
    
    {
      
      if (!(_strcmp(args[0], builts[i].prog)))
	
	{
	  
	  stat = (builts[i].builtin)(args, envi);
	  
	  break;
	  
	}
      
      i++;
      
    }
  

  
  return (stat);
  
}



/**

 * com_execute - will execute programs

 * @arg: array which contains program name and arguments

 *

 * Return: status number of executed program

 */

int com_execute(char **arg, env_t *envi)
  
{
  
  pid_t pcs;
  
  int stat = 0;
  

  
  stat = blt_execute(arg, envi);
  
  if (stat < 0)
    
    {
      

      
      pcs = fork();
      
      if (!pcs)
	
	{
	  
	  stat = execve(arg[0], arg, environ);
	  
	  if (stat == -1)
	    
	    perror("No such file or directory\n");
	  
	  free(arg[0]);
	  
	  free(arg);
	  
	  free_env(envi);
	  
	  exit(stat);
	  
	}
      
      else if (pcs < 0)
	
	perror("error forking\n");
      
      else
	
	{
	  
	  do {
	    
	    waitpid(pcs, &stat, WUNTRACED);
	    
	  } while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	  
	}
      
    }
  
  return (stat);
  
}

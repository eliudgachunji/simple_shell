#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - PPID
 * Return: Always 0.
 */

int main(void)
  
{
  
 pid_t my_ppid;
  

  
  my_ppid = getpid();
  
  printf("%u\n", my_ppid);
  
  return (0);
  
}
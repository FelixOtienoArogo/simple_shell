#include <stdio.h>
#include <unistd.h>

/**
 * main - av
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
  int i;
  i = 0;
  
  while(av[i])
    {
      printf("%s\n", av[i]);
      i++;
    }
    return (0);
}

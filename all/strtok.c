#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 *main - to text my own getline
 *
 *Return: Always 0
 *
 */
int main(void)
{
  char st[] = "I";
  char  d[] = " ";
  char *prt1;
  prt1 = strtok(st, d);
  while(prt1 != NULL)
    {
      /*  printf("%s\n", prt1);*/
  prt1 = strtok(NULL, d);
    }
  printf("%ld\n",strlen(st));    
  return(0);
}

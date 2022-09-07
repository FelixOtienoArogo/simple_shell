#include <stdio.h>
#include <stdlib.h>
extern char **environ;

/**
 *_getenv - gets an environment variable
 *
 *@name: the environmental variable
 *
 *Return: a pointer to the corresponding value string
 */
char *_getenv(const char *name)
{
  unsigned int i;

    i = 0;
    printf("befor\n");
    while (environ[i] != NULL)
    {
      printf("%s\n", environ[i]);
      if(environ[i] == name)
	{
        return (environ[i]);
	}
        i++;
    }
    return (NULL);
}

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
if(getenv("OLDPWD"))
printf("%s\n", getenv("OLDPWD"));
 
return (0);
}

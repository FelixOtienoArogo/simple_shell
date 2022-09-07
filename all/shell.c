#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *main - to text my own getline
 *
 *Return: Always 0
 *
 */
int main(void)
{
  char *lineptr;
  size_t n;
  char **token;
  int i, len, j;
  pid_t child_pid;

 while(1)
    {
  i = 0;
  n = 255;
  lineptr = malloc(sizeof(char) * n);/*the input string*/
  token = malloc(sizeof(char *) * n);/*the tokens */
  printf("$ ");
  getline(&lineptr, &n, stdin);
  len = strlen(lineptr);
  
  /* forking */
child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
      {
  /*this is for determining the outcome*/
  for(j =0 ; j < len + 1; j++)
    {
  if(lineptr[j] == ' ')
    {
  token[i] = strtok_r(lineptr, " ", &lineptr);
  break;
    }
  if(lineptr[j] == '\0')
    {
  token[i] = strtok_r(lineptr, "\r\n", &lineptr);
  break;
    }
    }
  i++;
  while(token[i] != NULL)
    {
      token[i] = strtok_r(NULL, " \0", &lineptr);
      i++;
    }
  token[i] = NULL;
   if (execvp(token[0], (char * const *)token) == -1)
    {
        perror("Error:");
    }
      
   /*free everything allocated */
  free(lineptr);
  i = 0;
  while(token[i + 1] != NULL)
    {
      free(token[i]);
      i++;
    }
  free(token);
    }
    wait(NULL);
    }
  return(0);
}

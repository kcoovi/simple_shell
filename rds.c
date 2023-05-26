#include "main.h"
/**
 * rds - rds
 * Return: 0
 */
char *rds(void)
{
int i = 0;
int bu = 1024;
char *n = malloc(sizeof(char) * bu);
int mychar;

if (n == NULL)
{
fprintf(stderr, "error");
exit(EXIT_FAILURE);
}
while (1)
{
mychar = getchar();
if (mychar == EOF)
{
free(n);
exit(EXIT_SUCCESS);
}
else if (mychar == '\n')
{
n[i] = '\0';
return (n);
}
else
{
n[i] = mychar;
}
i++;
if (i >= bu)
{
bu += bu;
n = realloc(n, bu);
if (n == NULL)
{
fprintf(stderr, "error");
exit(EXIT_FAILURE);
}
}
}
}

#include "main.h"
/**
 * rdl - rdl
 * Return: 0
 */
char *rdl(void)
{
size_t a = 0;
char *n = NULL;
ssize_t i;

i = getline(&n, &a, stdin);
if (i == -1)
{
if (feof(stdin))
{
free(n);
exit(EXIT_SUCCESS);
}
else
{
free(n);
perror("error");
exit(EXIT_FAILURE);
}
}
return (n);
}

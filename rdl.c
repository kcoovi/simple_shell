#include "main.h"

/**
 * rdl - rdl
 * Return: 0
 */
char *rdl(void)
{
char *n = NULL;
size_t bu = 0;

if (getline(&n, &bu, stdin) == -1)
{
if (feof(stdin))
{
free(n);
exit(EXIT_SUCCESS);
}
else
{
free(n);
perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
}
return (n);
}

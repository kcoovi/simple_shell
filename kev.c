#include "main.h"
/**
 * kev - kev
 * @a: a
 * Return: 0
 */
int kev(char **a)
{
if (a[1] == NULL)
{
fprintf(stderr, "error");
return (0);
}
if (chdir(a[1]) != 0)
{
perror("error");
return (0);
}
return (1);
}

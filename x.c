#include "main.h"
/**
 * x - function
 * @a: a
 * Return: 0
 */
int x(char **a)
{
int i = 0;

if (a[1] != NULL)
{
i = atoi(a[1]);
}
return (i);
}

#include "main.h"
/**
 * ninter - function
 * Return: 0
 */
void ninter(void)
{
char *n, **a;
int i = -1;

while (1)
{
n = rds();
a = sp(n);
i = exe(a);
free(n);
free(a);
if (i >= 0)
{
exit(i);
}
if (i != -1)
{
break;
}
}
}

#include "main.h"
/**
 * inter - function
 * Return: 0
 */
void inter(void)
{
char *n, **a;
int i = -1;

while (1)
{
printf(">> ");
n = rdl();
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

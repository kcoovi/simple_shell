#include "main.h"
/**
 * ninter - ninter
 * Return: 0
 */
void ninter(void)
{
char **args;
int i = -1;
char *n;

do {
n = rds();
args = spl(n);
i = exe(args);
free(n);
free(args);
if (i >= 0)
{
exit(i);
}
} while (i == -1);
}

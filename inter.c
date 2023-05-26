#include "main.h"
/**
 * inter - function
 * Return: 0
 */
void inter(void)
{
char *n;
char **args;
int i = -1;

do {
printf(">> ");
n = rdl();
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

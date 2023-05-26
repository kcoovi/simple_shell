#include "main.h"
/**
 * sp - function
 * @n: n
 * Return: 0
 */

char **sp(char *n)
{
int a = 64;
int i = 0;
char **ts = malloc(a * sizeof(char *));
char *j;
char **nts;

if (!ts)
{
fprintf(stderr, "error");
exit(EXIT_FAILURE);
}
j = strtok(n, D_TOK);
while (j != NULL)
{
int is_comment = (j[0] == '#');
if (is_comment)
{
break;
}
ts[i] = j;
i++;
if (i >= a)
{
a += a;
nts = realloc(ts, a *sizeof(char *));
if (!nts)
{
fprintf(stderr, "error");
exit(EXIT_FAILURE);
}
ts = nts;
}
j = strtok(NULL, D_TOK);
}
ts[i] = NULL;
return (ts);
}

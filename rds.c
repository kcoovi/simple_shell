#include "main.h"
/**
 * rds - function
 * Return: pointer to the read line
 */
char *rds(void)
{
	int i = 0;
	int a = 1024;
	char *n = malloc(sizeof(char) * a);
	int c;
	char *nl;

if (n == NULL)
{
fprintf(stderr, "allocation error in read_stream");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF)
{
free(n);
exit(EXIT_SUCCESS);
}
if (c == '\n')
break;
n[i] = c;
i++;
if (i >= a)
{
a += a;
nl = realloc(n, a);
if (nl == NULL)
{
fprintf(stderr, "error");
exit(EXIT_FAILURE);
}
n = nl;
}
}
n[i] = '\0';
return (n);
}

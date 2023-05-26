#include "main.h"
/**
 * spl - spl
 * @n: n
 * Return: 0
 */
char **spl(char *n)
{
	int i = 0;
	int bu = 64;
	char **ts = malloc(bu * sizeof(char *));
	char *j;

	if (!ts)
	{
	fprintf(stderr, "error\n");
	exit(EXIT_FAILURE);
	}
	j = strtok(n, D_TOK);
	while (j != NULL)
	{
	if (j[0] == '#')
	{
	break;
	}
	ts[i] = j;
	i++;
	if (i >= bu)
	{
	bu += bu;
	ts = realloc(ts, bu * sizeof(char *));
	if (!ts)
	{
	fprintf(stderr, "error");
	exit(EXIT_FAILURE);
	}
	}
	j = strtok(NULL, D_TOK);
	}
	ts[i] = NULL;
	return (ts);
}

#include "main.h"
/**
 * exe - function
 * @a: cmd
 * Return: 0
 */
int exe(char **a)
{
char *cmd[] = {
"kev",
"kenv",
"x"
};
int (*b[])(char **) = {
&kev,
&kenv,
&x
};
unsigned long int i = 0;

if (a[0] == NULL)
{
return (-1);
}
for (; i < sizeof(cmd) / sizeof(char *); i++)
{
if (strcmp(a[0], cmd[i]) == 0)
{
return ((*b[i])(a));
}
}
return (np(a));
}

#include "main.h"
/**
 * exe - function
 * @args: cmd
 * Return: 0
 */
int exe(char **args)
{
char *cmd1[] = {
"myenv",
"myexit"
};
int (*cmd2[])(char **) = {
&myenv,
&myexit
};
long unsigned int i = 0;

if (args[0] == NULL)
{

return (-1);
}

for (; i < sizeof(cmd1) / sizeof(char *); i++)
{

if (strcmp(args[0], cmd1[i]) == 0)
{
return ((*cmd2[i])(args));
}
}
return (np(args));
}

#include "main.h"
/**
 * myexit - function
 * @args: cmd
 * Return: 0
 */
int myexit(char **args)
{

if (args[1])
{
return (atoi(args[1]));
}
else
{
return (0);
}
}

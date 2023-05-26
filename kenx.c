#include "main.h"
/**
 * kenx - function
 * @args: cmd
 * Return: 0
 */
int kenx(char **args)
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

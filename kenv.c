#include "main.h"
/**
 * kenv - env
 * @args: cmd
 * Return: 0
 */
int kenv(char **args)
{
int i = 0;
(void)(**args);

while (environ[i])
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (-1);
}

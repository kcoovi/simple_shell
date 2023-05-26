#include "main.h"
/**
 * kenv - kenv
 * @a: a
 * Return: 0
 */
int kenv(char **a)
{
int i = 0;
(void)(**a);
while (env[i] != NULL)
{
write(STDOUT_FILENO, env[i], strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (1);
}

#include "main.h"
/**
 * np - function
 * @args: cmd
 * Return: 0
 */
int np(char **args)
{
pid_t pid;
int i;

pid = fork();
if (pid ==  0)
{

if (execvp(args[0], args) == -1)
{
perror("error");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{

perror("error");
}
else
{

do {
waitpid(pid, &i, WUNTRACED);
} while (!WIFEXITED(i) && !WIFSIGNALED(i));
}
return (-1);
}

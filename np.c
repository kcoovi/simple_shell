#include "main.h"
/**
 * np - function
 * @a: a
 * Return: 0
 */
int np(char **a)
{
pid_t pid;
int i;

pid = fork();
if (pid == 0)
{
if (execvp(a[0], a) == -1)
{
perror("error in new_process: child process");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("error");
}
else
{
do {
if (waitpid(pid, &i, WUNTRACED) == -1)
{
perror("error");
}
} while (!WIFEXITED(i) && !WIFSIGNALED(i));
}
return (1);
}


#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define LENGTH 1024
/**
 * display - function
 */
void display(void)
{
printf("> ");
}
/**
 * rd - funcion
 * @cmd: cmd
 */
void rd(char *cmd)
{
fgets(cmd, LENGTH, stdin);

cmd[strcspn(cmd, "\n")] = '\0';
}
/**
 * int_cmd - function
 * @args: args
 */
void int_cmd(char *args[])
{
if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
else if (strcmp(args[0], "cd") == 0)
{
if (args[1] != NULL)
{
if (chdir(args[1]) != 0)
perror("cd");
}
}
}
/**
 * ext_cmd - function
 * @args: args
 */
void ext_cmd(char *args[])
{
pid_t pid = fork();

if (pid == 0)
{
execvp(args[0], args);
perror("execvp");
exit(1);
}
else if (pid > 0)
{
wait(NULL);
}
else
{
perror("fork");
}
}
/**
 * exe - exe
 * @cmd: cmd
 * Return: 0
 */
void exe(const char *cmd)
{
if (strlen(cmd) == 0)
return;

char *args[LENGTH];
char *okt = strtok((char *)cmd, " ");
int i = 0;
while (okt != NULL)
{
args[i++] = okt;
okt = strtok(NULL, " ");
}
args[i] = NULL;
int_cmd(args);
ext_cmd(args);
}

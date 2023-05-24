#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1024
/**
 * main - Beg
 * Return: 0
 */
int main(void)
{
char cmd[MAX_LENGTH];

while (1)
{
dpl_prompt();
rd_cmd(cmd);
exe_cmd(cmd);
}

return (0);
}
/**
 * dpl_prompt - function
 */
void dpl_prompt(void)
{
printf("($) ");
}
/**
 * rd_cmd - function
 * @cmd: command
 */
void rd_cmd(char *cmd)
{
fgets(cmd, MAX_LENGTH, stdin);
cmd[strcspn(cmd, "\n")] = '\0';
}
/**
 * exe_cmd - function
 * @cmd: command
 * Return: 0
 */
void exe_cmd(const char *cmd)
{
if (strlen(cmd) == 0)
return;
printf("Exe cmd: %s\n", cmd);
}

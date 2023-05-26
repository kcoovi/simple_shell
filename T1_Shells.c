#include "simple_shell.h"
#include <stdio.h>
/**
 * main - function
 * Return: 0
 */

int main(void)
{
char *command;
while (1)
{
printf("$ ");
command = read_command();
execute_command(command);
free(command);
}
return (0);
}

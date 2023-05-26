#include "simple_shell.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10
/**
 * main - function
 * Return: 0
 */
int main(void)
{
char input[MAX_INPUT_LENGTH];
char *args[MAX_ARGS];
int i;

while (1)
{
printf("$ ");
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0';
char *token = strtok(input, " ");
i = 0;
while (token != NULL && i < MAX_ARGS - 1)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;

if (args[0] != NULL)
{
execute_command(args);
}
}
return (0);
}

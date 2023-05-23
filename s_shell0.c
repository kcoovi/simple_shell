#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024
/**
 * execute_command - Function that executes a command in process child
 * @command: command to be executed.
 * Return: 0
 */

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)

	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	char *args[MAX_INPUT_LENGTH];
	int i = 0;
	char *token = strtok(command, " \t\n");

	while (token)
	{
	args[i++] = token;
	token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	if (execvp(args[0], args) == -1)
	{
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(NULL);
	}
}
/**
 * main - A shell entry point.
 * Return: 0.
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
	printf("shell> ");
	fflush(stdout);

	if (fgets(input, sizeof(input), stdin) == NULL)
	break;

	input[strcspn(input, "\n")] = '\0';

	execute_command(input);
	}

	return (0);
}

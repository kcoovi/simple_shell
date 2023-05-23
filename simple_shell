#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

#define MAX_INPUT_LENGTH 1024

void display_prompt(void);
void execute_command(char *command);

/**
 * main - programs entry point.
 * Return: 0.
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
	display_prompt();

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
	printf("\n");
	break;
	}

	input[strcspn(input, "\n")] = '\0';

	if (strlen(input) == 0)
	continue;

	execute_command(input);
	}

	return 0;
}

/**
 * display_prompt - Shows the output of the shell
 * Return: 0;
 */

void display_prompt(void)
{
	printf("shell> ");
	fflush(stdout);
}

/**
 * execute_command - Child process command executer
 * @command: Executed command
 * Return: 0;
 */

void execute_command(char *command)
{
	pid_t pid = fork();
	if (pid == -1)
{
	perror("fork");
	exit(EXIT_FAILURE)
}
	else if (pid == 0)
{
	execlp(command, command, NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
}
	else
{
	wait(NULL);
}
}

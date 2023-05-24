#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

void display_prompt(void);
void execute_command(char *command);

/**
 * main - The entry of the shell.
 * Return: 0
 **/

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
	display_prompt();

	if (fgets(input, sizeof(input), stdin) == NULL)
	printf("\n");
	break;
	}
	input[strcspn(input, "\n")] = '\0';
	if (strlen(input) > 0)
	{
	execute_command(input);
	}
	}

	return (0);
}

/**
 * display_prompt - displays on the shell
 **/

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * execute_command - Executes shell commands.
 * @command: The command to be executed in the shell.
 **/

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
	char executable[PATH_MAX];

	snprintf(executable, sizeof(executable), "/bin/%s", command);
	if (access(executable, X_OK) != -1)
	{
	char *args[] = {executable, NULL};

	execve(executable, args, NULL);
	perror("execve");
	}
	else
	{
	printf("Command not found: %s\n", command);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(NULL);
	}
}


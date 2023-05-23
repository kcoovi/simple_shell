#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

void display_prompt(void);
void execute_command(char *command);

/**
 * main - start of the program.
 * Return: 0 on success.
 **/

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
	return (0);
}

/**
 * display_prompt - shows the shell prompt.
 * Return: nothing.
 **/

void display_prompt(void)
{
	printf("shell> ");
	fflush(stdout);
}

/**
 * execute_command - Command executer in the shell.
 * @command: The executed command.
 * Return: Nothing.
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
	char *args[] = {command, NULL};

	if (execve(command, args, environ) == -1)
	{
	perror("execve");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(NULL);
	}
}

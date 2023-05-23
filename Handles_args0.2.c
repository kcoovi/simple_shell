#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void display_prompt(void);
void execute_command(char *command);

/**
 * main - Start point of the program.
 * Description: A prompt is displayed and waits for user.
 * Return: 0;
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

	char *command = strtok(input, " ");
	char *arguments[MAX_INPUT_LENGTH];
	int arg_count = 0;

	while (command != NULL && arg_count < MAX_INPUT_LENGTH - 1)
	{
	arguments[arg_count] = command;
	arg_count++;
	command = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;

	execute_command(arguments);
	}

	return (0);
}

/**
 * display_prompt - Outputs the shell prompt on monitor.
 * description: The display shows the shell prompt.
 * Return: Nothing
 **/

void display_prompt(void)
{
	printf("shell> ");
	fflush(stdout);
}

/**
 * execute_command - Is a shell command executer.
 * @arguments: Array of strings
 * Return: None
 **/

void execute_command(char *arguments[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execvp(arguments[0], arguments) == -1)
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

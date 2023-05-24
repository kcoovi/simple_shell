#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#define MAXLINE 1024

void sigintHandler(int);
char *myPrompt = "$ ";

/**
 * main - Begining of the program.
 * @argc: Command-line arguments number.
 * @argv: Command-line arguments Array.
 * Return: EXIT_SUCCESS on completion.
 **/

int main(int argc, char **argv)

{
	int status;
	char cmd[MAXLINE];
	char *envp[] = { "MYVAR=value", NULL };

	if (argc > 1)
	{
	myPrompt = argv[1];
	}
	signal(SIGINT, sigintHandler);
	while ((fputs(myPrompt, stdout)) && (fgets(cmd, sizeof(cmd), stdin)))
	{
	printf("Executing \"%s\"\n", cmd);
	status = system(cmd);
	if (status == -1)
	perror("system");
	else
	fprintf(stderr, "Exit Status:%d\n", WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}

/**
 * sigintHandler - The SIGINT signal (Ctrl+C) Handler.
 * @signo: Received signal number.
 *
 * Description: The function is called if  SIGINT signal (Ctrl+C) is
 * received and displays a message showing the signal and leaves the program.
 **/

void sigintHandler(int signo)
{
	puts("\nCaught CTRL-C... exiting.\n");
	exit(signo);
}

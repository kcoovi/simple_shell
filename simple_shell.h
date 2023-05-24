#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* include required libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define MAX_INPUT_LENGTH 1024

void execute_command(char *command);
void handle_input(char *input);

/* define constant variable */

typedef struct Command{
	    char** args;
	    size_t numArgs;
	 }Command;
void initCmdStruct(Command*); 
void destroyCmdStruct(Command*);
void parseInputLine(const char*, Command*); 
	 
extern const char* PROMPT;

extern char **environ;

void display_prompt(void);
void execute_command(char *arguments[]);

#endif /* SIMPLE_SHELL_H */


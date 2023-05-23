#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_INPUT_LENGTH 1024

void execute_command(char *command);
void handle_input(char *input);

void display_prompt(void);
void execute_command(char *command);

extern char **environ;

void display_prompt(void);
void execute_command(char *arguments[]);

#endif /* SIMPLE_SHELL_H */


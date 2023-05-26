#ifndef SHELL_H
#define SHELL_H


char *read_command(void);
void execute_command(const char *command, char *args[]);
void execute_env(void);
void execute_exit(void);
char *get_full_path(const char *command);

#endif

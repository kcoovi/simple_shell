#ifndef SHELL_H
#define SHELL_H

void execute_command(const char *command, char *args[]);
void execute_env(void);
void execute_exit(void);
char *get_full_path(const char *command);

#endif

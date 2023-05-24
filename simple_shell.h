#ifndef SHELL_H
#define SHELL_H

void display(void);
void rd(char *cmd);
void exe(const char *cmd);
void int_cmd(char *args[]);
void ext_cmd(char *args[]);
#endif

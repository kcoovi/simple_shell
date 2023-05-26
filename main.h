#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define D_TOK " \t\r\n\a\""
extern char **environ;

void inter(void);
void ninter(void);

char *rdl(void);
char **spl(char *n);
int exe(char **args);

int np(char **args);

char *rds(void);

int myexit(char **args);
int myenv(char **args);
#endif

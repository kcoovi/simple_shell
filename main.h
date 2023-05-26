#ifndef MAIN_H
#define MAIN_H

#define D_TOK " \t\r\n\a\""
extern char **env;
void inter(void);
void ninter(void);
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
char *rdl(void);
char **sp(char *n);
int exe(char **a);

int kev(char **a);
int x(char **a);
int kenv(char **a);
int np(char **a);
char *rds(void);
#endif

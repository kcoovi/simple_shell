#include "main.h"
/**
 * main - function
 * Return: 0
 */
int main(void)
{
int term;
term = isatty(STDIN_FILENO);
switch (term)
{
case 1:
inter();
break;
default:
ninter();
break;
}
return (0);
}

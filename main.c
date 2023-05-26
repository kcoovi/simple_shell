#include "main.h"
/**
 * main - function
 * Return: 0
 */
int main(void)
{

if (isatty(STDIN_FILENO) == 1)
{
inter();
}
else
{
ninter();
}
return (0);
}

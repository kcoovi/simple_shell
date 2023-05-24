#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - function
 * Return: 0
 */

int main(void)
{
while (1)
{
display();
rd();
exe();
}

return (0);
}
/**
 * display - function
 */
void display(void)
{
printf("($) ");
}
/**
 * rd - read
 */
void rd(void)
{
char cmd[1024];

if (fgets(cmd, sizeof(cmd), stdin) == NULL)
{
printf("\n");
exit(0);
}
}
/**
 * exe - function
 */
void exe(void)
{

}

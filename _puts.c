#include "main.h"

/**
 * _puts - print a string
 * @s: a string
 * Return: integer
*/
int _puts(char *s)
{
char *pointr = s;

while (*s)
	_putchar(*str++);
return (str - pointr);
}

/**
 * _putchar - write a character
 * @c: character
 * Return: 0 success
*/
int _putchar(int c)
{
static int j;
static char buff[BUFFER_S];
if (c == BUFFER_FLUSH || j >= BUFFER_S)
{
	write(1, buff, j);
	j = 0;
}
if (c != BUFFER_FLUSH)
	buff[j++] = c;
return (1);
}

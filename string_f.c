#include "main.h"

/**
 * get_precision - getsprecision from the format string
 * @str: string
 * @par: the param struct
 * @pr: argument
 * Return: integer
*/

char *get_precision(char *str, para_t *par, va_list pr)
{
int l = 0;
if (*str != '.')
	return (str);
str++;
if (*str == '*')
{
	l = va_arg(pr, int);
	str++;
}
else
{
	while (digit(*str))
		l = l * 10 + (*str++ - '0');
}
par->precision = l;
return (str);
}

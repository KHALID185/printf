#include "main.h"

/**
 * digit - check is digit
 * @c: the character
 * Return: integer
*/

int digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * len_s - length of string
 * @str: stroing
 * Return: integer (length)
*/
int len_s(int *str)
{
	int j = 0;

	while (*str++)
		j++;
	return (j);
}

/**
 * print_num - print anumber
 * @str: string
 * @par: parametres structure
 * Return: integr
*/

int print_num(char *str, para_t *par)
{
unsigned int j = len_s(str);
int ngt = (!par->u_f && *str == '-');

	if (!par->precision && *str == '0' && !str[1])
		str = "";
	if (ngt)
	{
		str++;
		j--;
	}
	if (par->precision != UINT_MAX)
	{
		while (j++ < par->precision)
			*--str = '0';
	}
	if (ngt)
		*--str = '-';

	if (!par->m_f)
		return (print_num_r(str, par));
	else
		return (print_num_l(str, par));

}

/**
 * print_num_r - print a number with options right
 * @str: the string
 * @par: parametres struct
 * Return: integer
*/

int print_num_r(char *str, para_t *par)
{
unsigned int n = 0, ng, ng2, i = len_s(str);
char pad_ch = ' ';

if (par->z_f && !par->m_f)
	pad_ch = '0';
ng = ng2 = (!par->u_f && *str == '-');
if (ng && i < par->wdth && pad_ch == '0' && !par->m_f)
	str++;
else
	ng = 0;
if ((par->p_f && !ng2) || (!par->p_f && par->s_f && !ng2))
	i++;
if (ng && pad_ch == '0')
	n += _putchar('-');
if (par->p_f && !ng2 && pad_ch == '0' && !par->u_f)
	n += _putchar('+');
else if (!par->p_f && par->s_f && !ng2 && !par->u_f && par->z_f)
	n += _putchar(' ');
while (i++ < par->wdth)
	n += _putchar(pad_ch);
if (ng && pad_ch == ' ')
	n += _putchar('-');
if (par->p_f && !ng2 && pad_ch == ' ' && !par->u_f)
	n += _putchar('+');
else if (!par->p_f && par->s_f && !ng2 && !par->u_f && !par->z_f)
	n += _putchar (' ');
n += _puts(str);
return (n);
}

/**
 * print_num_l - prints a number with options left
 * @str: string
 * @par: parametres
 * Return: integer
*/
int print_num_l(char *str, para_t *par)
{
unsigned int n = 0, ng, ng2, i = len_s(str);
char pad_ch = ' ';

if (par->z_f && !par->m_f)
	pad_ch = '0';
ng = ng2 = (!par->u_f && *str == '-');
if (ng && i < par->wdth && pad_ch == '0' && !par->m_f)
	str++;
else
ng = 0;
if (par->p_f && !ng2 && !par->u_f)
	n += _putchar(+), i++;
else if (par->s_f && !ng2 && !par->u_f)
	n += _putchar(' '), i++;
n += _puts(str);
while (i++ < par->wdth)
	n += _putchar(pad_ch);
	return (n);

}

#include "main.h"

/**
 * print_char - print character
 * @pr: argument
 * @par: parametres structure
 * Return: integer
*/

int print_char(va_list pr, para_t *par)
{
	char pad_ch = ' ';
	unsigned int pd = 1, s = 0, chr = va_arg(pr, int);

	if (par->m_f)
		s += _putchar(chr);
	while (pd++ < par->wdth)
		s += _putchar(pad_ch);
	if (!par->m_f)
		s += _putchar(chr);
	return (s);
}

/**
 * print_int - print integer
 * @pr: argument
 * @par: parametres structure
 * Return: integer
*/

int print_int(va_list pr, para_t *par)
{
long k;

if (par->l_modif)
	k = va_arg(pr, long);
else if (par->h_modif)
	k = (short int)va_arg(pr, int);
else
	k = (int)va_arg(pr, int);
return (print_num(conv_num(k, 10, 0, par), par));
}

/**
 * print_string - print string
 * @pr: argument
 * @par: parametres structure
 * Return: integer
*/

int print_string(va_list pr, para_t *par)
{
	char *strg = va_arg(pr, char *), pad_ch = ' ';
	unsigned int pd = 0, s = 0, i = 0, j;

	(void)par;
	switch ((int)(!strg))
		case 1:
			strg = NULL_STR;
	j = pd = len_s(strg);
	if (par->precision < pd)
		j = pd = par->precision;

	if (par->m_f)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				s += _putchar(*strg++);
		else
			s += _puts(strg);
	}
	while (j++ < par->wdth)
		s += _putchar(pad_ch);
	if (par->m_f)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				s += _putchar(*strg++);
		else
			s += _puts(strg);
	}
	return (s);
}

/**
 * print_percent - print percent
 * @pr: argument
 * @par: parametres structure
 * Return: integer
*/

int print_percent(va_list pr, para_t *par)
{
(void)pr;
(void)par;
return (_putchar('%'));
}

/**
 * print_S - custum format specified
 * @pr: argument
 * @par: parametres structure
 * Return: integer
*/

int print_S(va_list pr, para_t *par)
{
	char *strg = va_arg(pr, char *);
	char *hx;
	int s = 0;

	if ((int)(!strg))
		return (_puts(NULL_STR));
	for (; *strg; strg++)
	{
		if ((*strg > 0 && *strg < 32) || *strg >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			hx = conv_num(*strg, 16, 0, par);
			if (!hx[1])
				s += _putchar('0');
			s += puts(hx);
		}
		else
		{
		s += _putchar(*strg);
		}
	}
	return (s);
}

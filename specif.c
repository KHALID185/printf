#include "main.h"

/**
 * get_specif - find the format
 * @str: format string
 * Return: numbers of bytes printed
*/
int (*get_specif(char *str))(va_list pr, para_t *par)
{
specif_t specifs[] = {
	{"c", print_char},
	{"d", print_int},
	{"i", print_int},
	{"s", print_string},
	{"%", print_percent},
	{"b", print_bi},
	{"o", print_oc},
	{"u", print_uns},
	{"x", print_hex},
	{"X", print_hex_u},
	{"p", printf_ad},
	{"S", print_S},
	{"r", print_rev},
	{"R", print_r13},
	{NULL, NULL}
	};
	int j;

	while (specifs[j].specif)
	{
		if (*str == specifs[j].specif[0])
		{
			return (specifs[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * get_p_fct - find the format function
 * @str: string
 * @par: parametre structure
 * @pr: argument
 * Return: numbers of bytes printed
*/

int get_p_fct(char *str, va_list pr, para_t *par)
{
int (*f)(va_list, para_t *) = get_specif(str);

if (f)
	return (f(pr, par));
return (0);
}

/**
 * get_f - find flags function
 * @str: string
 * @par: parametre structure
 * Return: integer
*/

int get_f(char *str, para_t *par)
{
int j = 0;
	switch (*str)
	{
		case '+':
				j = par->p_f = 1;
			break;
		case ' ':
				j = par->s_f = 1;
			break;
		case '%':
				j = par->hax_f = 1;
			break;
		case '-':
				j = par->m_f = 1;
			break;
		case '0':
				j = par->z_f = 1;
			break;

	}
return (j);
}

/**
 * get_modif - find the modifier function
 * @str: string
 * @par: the parametres struct
 * Return: integer
*/
int get_modif(char *str, para_t *par)
{
int j = 0;
	switch (*str)
	{
		case 'h':
				j = par->h_modif = 1;
			break;
		case 'l':
				j = par->l_modif = 1;
			break;

	}
	return (j);
}

/**
 * get_wdth - get the width from the format string
 * @str: string
 * @par:the parametres structure
 * @pr:the argument pointer
 * Return: character
*/

char *get_wdth(char *str, para_t *par, va_list pr)
{
int w = 0;
if (*str == '*')
{
	w = va_arg(pr, int);
	str++;
}
else
{
	while (digit(*str))
		w = w * 10 + (*str++ - '0');
}
par->wdth = w;
return (str);
}

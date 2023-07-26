#include "main.h"

/**
 * print_hex - print en haxadecimal
 * @pr: arguments
 * @par: parametres strct
 * Return: integr
*/
int print_hex(va_list pr, para_t *par)
{
	unsigned long k;
	int c_n = 0;
	char *strg;

	if (par->l_modif)
		k = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_modif)
		k = (unsigned short int)va_arg(pr, unsigned int);
	else
		k = (unsigned int)va_arg(pr, unsigned int);
	strg = conv_num(k, 16, CONVERT_UNS | CONVERT_L, par);
	if (par->hax_f && k)
	{
	*--strg = 'x';
	*--strg = '0';
	}
	par->u_f = 1;
	return (c_n += print_num(strg, par));
}

/**
 * print_hex_u - print en haxadecimal uppercase
 * @pr: arguments
 * @par: parametres strct
 * Return: integr
*/
int print_hex_u(va_list pr, para_t *par)
{
	unsigned long k;
	int c_n = 0;
	char *strg;

	if (par->l_modif)
		k = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_modif)
		k = (unsigned short int)va_arg(pr, unsigned int);
	else
		k = (unsigned int)va_arg(pr, unsigned int);
	strg = conv_num(k, 16, CONVERT_UNS, par);
	if (par->hax_f && k)
	{
		*--strg = 'X';
		*--strg = '0';
	}
	par->u_f = 1;
	return (c_n += print_num(strg, par));
}

/**
 * print_bi - print en binaire
 * @pr: arguments
 * @par: parametres structures
 * Return: integer
*/

int print_bi(va_list pr, para_t *par)
{
	unsigned int nm = va_arg(pr, unsigned int);
	char *strg = conv_num(nm, 2, CONVERT_UNS, par);
	int c_n = 0;

	if (par->hax_f && nm)
		*--strg = '0';
	par->u_f = 1;
	return (c_n += print_num(strg, par));
}
/**
 * print_oc - print en octal
 * @pr: arguments
 * @par: parametres structures
 * Return: integer
*/

int print_oc(va_list pr, para_t *par)
{
unsigned long k;
char *strg;
int c_n = 0;

if (par->l_modif)
	k = (unsigned long)va_arg(pr, unsigned long);
else if (par->h_modif)
	k = (unsigned short int)va_arg(pr, unsigned int);
else
	k = (unsigned int)va_arg(pr, unsigned int);
strg = conv_num(k, 8, CONVERT_UNS, par);

if (par->hax_f && k)
	*--strg = '0';
par->u_f = 1;
return (c_n += print_num(strg, par));
}

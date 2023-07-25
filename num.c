#include "main.h"

/**
 * conv_num - convert function
 * @n: number
 * @b: base
 * @f: flags
 * @par: parametres structure
 * Return: string
*/

int *conv_num(long int n, int b, int f, para_t *par)
{
static char *lst;
static char bufff[50];
char sgn = 0;
char *pntr;
unsigned long n_1 = n;
(void)par;

if (!(f & CONVERT_UNS) && n < 0)
{
	n = -n_1;
	sgn = '-';
}
lst = f & CONVERT_L ? "0123456789abcdef" : "0123456789ABCDEF";
pntr = &bufff[49];
*pntr = '\0';

	do {
	*--pntr = lst[n_1 % b];
	n_1 /= b;
	} while (n_1 != 0);
if (sgn)
	*--pntr = sgn;
return (pntr);
}

/**
 * print_uns - print unsigned numbers
 * @pr: argument
 * @par: parametres struct
 * Return: integer
*/

int print_uns(va_list pr, para_t *par)
{
	unsigned long byt;

	if (par->l_modif)
		byt = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_modif)
		byt = (unsigned short int)va_arg(pr, unsigned int);
	else
		byt = (unsigned int)va_arg(pr, unsigned int);
	par->u_f = 1;
	return (print_num(conv_num(byt, 10, CONVERT_UNS, par)));
}

/**
 * printf_ad - print adress
 * @pr: argument
 * @par: parametres structure
 * Return: ineger
*/

int printf_ad(va_list pr, para_t *par)
{
	unsigned long n_2 = va_arg(pr, unsigned long int);
	char *strg;

	if (!n_2)
		return (_puts("(nil)"));
	strg = conv_num(n_2, 16, CONVERT_UNS | CONVERT_L, par);
	*--strg = 'x';
	*--strg = '0';
	return (print_num(strg, par));

}

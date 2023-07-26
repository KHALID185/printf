#include "main.h"

/**
 * printf_fto - print a range of char adress
 * @start : starting
 * @stp: ending
 * @exep: except adrss
 * Return: integer
*/
int printf_fto(char *start, char *stp, char *exep)
{
int s = 0;

while (start <= stp)
{
	if (start != exep)
		s += _putchar(*start);
	start++;

}
return (s);
}
/**
 * print_rev - reverse print
 * @pr: string
 * @par: parametres struct
 * Return: integer
*/

int print_rev(va_list pr, para_t *par)
{
int l, s = 0;
char *st = va_arg(pr, char *);
(void)par;

	if (st)
	{
		for (l = 0; *st; st++)
			l++;
		st--;
		for (; l > 0; l--, st--)
			s += _putchar(*st);
	}
	return (s);

}
/**
 * print_r13 - print strint in rot 13
 * @pr: argument
 * @par: parametres stuct
 * Return: integer
*/

int print_r13(va_list pr, para_t *par)
{
	int j, ind;
	int cnt = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(pr, char *);
	(void)par;

	j = 0;
	ind = 0;
	while (a[j])
	{
		if ((a[j] >= 'A' && a[j] <= 'Z') || (a[j] >= 'a' && a[j] <= 'z'))
		{
			ind = a[j] - 65;
			cnt += _putchar(arr[ind]);
		}
		else
			cnt += _putchar(a[j]);
		j++;
	}
	return (cnt);

}

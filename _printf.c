#include "main.h"

/**
 * _printf - prints anything
 * @format: the string format
 * @...: arguments
 * Return: integer
*/
int _printf(const char *format, ...)
{
	int s = 0;
	va_list pr;
	char *str, *start;
	para_t par = PARA_INIT;

	va_start(pr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = (char *)format; *str; str++)
	{
		init_para(&par, pr);
		if (*str != '%')
		{
			s += _putchar(*str);
			continue;
		}
		start = str;
		str++;
		while (get_f(str, &par))
		{
			str++;
		}
		str = get_wdth(str, &par, pr);
		str = get_precision(str, &par, pr);
		if (get_modif(str, &par))
			str++;
		if (!get_specif(str))
			s += printf_fto(start, str, par.l_modif || par.h_modif ? str - 1 : 0);
		else
			s += get_p_fct(str, pr, &par);
	}
	_putchar(BUFFER_FLUSH);
	va_end(pr);
	return (s);
}

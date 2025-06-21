#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Imprime un carácter
 * @c: Carácter a imprimir
 *
 * Return: Número de caracteres impresos
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Imprime una cadena
 * @s: Cadena a imprimir
 *
 * Return: Número de caracteres impresos
 */
int print_str(char *s)
{
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

/**
 * _printf - Imprime una cadena formateada (soporta %c, %s, %%)
 * @format: Cadena de formato
 *
 * Return: Número de caracteres impresos, o -1 si error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			i++;
			if (format[i] == 'c')
				count += print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += print_str(va_arg(args, char *));
			else if (format[i] == '%')
				count += print_char('%');
			else
				count += write(1, &format[i], 1);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

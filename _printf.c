#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Print a character
 * @C: Character to print
 * Return: number of printed characters
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - print a string
 * @s: String to print
 * Return: number of printed characters
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
 * _printf - Printf type function with %C, %s and %%
 * @format: format string
 * Return: number of printed characters or -1 if error
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
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += print_str(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(va_arg(args, int));
			else if (format[i] == '%')
				count += print_char('%');
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			va_end(args);
			return (-1);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (c);
}

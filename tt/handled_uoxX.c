#include "main.h"
#include <stdarg.h>

/**
 * _printf - our magical printf function
 * @format: the inserted format
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += I_handle_number_specifiers(args, format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * I_handle_number_specifiers - handle the numbers specifiers.
 * @args: arguments
 * @format: format
 * Return: handls
 */

int I_handle_number_specifiers(va_list args, const char *format)
{
	int count = 0;

	switch (*format)
	{
		case 'u':
			count += I_handle_u_specifier(va_arg(args, unsigned int));
			break;
		case 'o':
			count += I_handle_o_specifier(va_arg(args, unsigned int));
			break;
		case 'x':
			count += I_handle_x_specifier(va_arg(args, unsigned int));
			break;
		case 'X':
			count += I_handle_X_specifier(va_arg(args, unsigned int));
			break;
		default:
			return (-1);
	}

	return (count);
}


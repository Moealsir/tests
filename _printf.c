#include "main.h"
#include <stdarg.h>

/**
 * handlies specifier untill now:
 * 1. s
 * 2. c
 * 3. %
 * 4. b
*/

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
                case 'd':
                    count += I_handle_d_specifier(va_arg(args, int));
                    break;
                case 'b':
                    count += I_handle_b_specifier(va_arg(args, int));
                    break;
                default:
                    return (-1);
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
 * I_handle_d_specifier - handle the %d specifier.
 * @n: integer
 * Return: count + _putchar(n % 10 + '0')
 */
int I_handle_d_specifier(int n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }
    if (n / 10 != 0)
    {
        count += I_handle_d_specifier(n / 10);
    }
    return (count + _putchar(n % 10 + '0'));
}

/**
 * I_handle_b_specifier - handle the %b specifier.
 * @n: integer
 * Return: count + binary representation
 */
int I_handle_b_specifier(int n)
{
    int count = 0;
    int leadingZero = 1;
    int i;

    for (i = 31; i >= 0; i--)
    {
        char bit = (n >> i) & 1;
        if (bit == 1)
        {
            leadingZero = 0;
        }

        if (!leadingZero)
        {
            count += _putchar(bit + '0');
        }
    }

    if (count == 0)
    {
        count += _putchar('0');
    }

    return (count);
}

/**
 * I_handle_i_specifier - handle the %i specifier for various bases.
 * @n: integer
 * Return: count
 */
int I_handle_i_specifier(int n)
{
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += _putchar(n + '0');

    return (count);
}

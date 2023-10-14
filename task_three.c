#include "main.h"

unsigned int ui = 0;

/**
 * I_handle_u_specifier - handle the unsigned decimal %u specifier.
 * @n: integer
 * Return: count + unsigned decimal representation
 */
int I_handle_u_specifier(unsigned int n)
{
    int count = 0;

    if (n / 10 != 0)
    {
        count += I_handle_u_specifier(n / 10);
    }
    return (count + _putchar(n % 10 + '0'));
}

/**
 * I_handle_o_specifier - handle the octal %o specifier.
 * @n: integer
 * Return: count + octal representation
 */
int I_handle_o_specifier(unsigned int n)
{
    int count = 0;

    if (n / 8 != 0)
    {
        count += I_handle_o_specifier(n / 8);
    }
    return (count + _putchar(n % 8 + '0'));
}

/**
 * I_handle_x_specifier - handle the lowercase hexadecimal %x specifier.
 * @n: integer
 * Return: count + lowercase hexadecimal representation
 */
int I_handle_x_specifier(unsigned int n)
{
    int count = 0;
    int digit;

    if (n / 16 != 0)
    {
        count += I_handle_x_specifier(n / 16);
    }

    digit = n % 16;
    count += _putchar((digit < 10) ? (digit + '0') : (digit - 10 + 'a'));

    return count;
}

/**
 * I_handle_X_specifier - handle the uppercase hexadecimal %X specifier.
 * @n: integer
 * Return: count + uppercase hexadecimal representation
 */
int I_handle_X_specifier(unsigned int n)
{
    int count = 0;
    int digit;

    if (n / 16 != 0)
    {
        count += I_handle_X_specifier(n / 16);
    }

    digit = n % 16;
    count += _putchar((digit < 10) ? (digit + '0') : (digit - 10 + 'A'));

    return count;
}

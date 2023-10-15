#include "main.h"

/**
 * I_handle_u_specifier - handle the unsigned decimal %u specifier.
 * @n: integer
 * Return: count + unsigned decimal representation
 */
int I_handle_u_specifier(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count += _putchar(n % 10 + '0');
		n /= 10;
	}

	return (count);
}

/**
 * I_handle_o_specifier - handle the octal %o specifier.
 * @n: integer
 * Return: count + octal representation
 */
int I_handle_o_specifier(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count += _putchar(n % 8 + '0');
		n /= 8;
	}

	return (count);
}

/**
 * I_handle_x_specifier - handle the lowercase hexadecimal %x specifier.
 * @n: integer
 * Return: count + lowercase hexadecimal representation
 */
int I_handle_x_specifier(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count += _putchar("0123456789abcdef"[n % 16]);
		n /= 16;
	}

	return (count);
}

/**
 * I_handle_X_specifier - handle the uppercase hexadecimal %X specifier.
 * @n: integer
 * Return: count + uppercase hexadecimal representation
 */
int I_handle_X_specifier(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count += _putchar("0123456789ABCDEF"[n % 16]);
		n /= 16;
	}

	return (count);
}

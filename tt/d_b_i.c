#include "main.h"


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
		char bit;

		bit = (n >> i) & 1;

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


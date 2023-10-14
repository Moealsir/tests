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

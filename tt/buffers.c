#include "main.h"


/**
 * write_buffer - Write the buffer to standard output
 * @buffer: The buffer to write
 * @count: The number of characters in the buffer
 */
void write_buffer(char *buffer, int *count)
{
	write(1, buffer, *count);
	*count = 0;
}

/**
 * handle_char - Handle the 'c' specifier
 * @args: Argument
 * @buffer: A buffer
 * @count: Counter
 */
void handle_char(va_list args, char *buffer, int *count)
{
	buffer[(*count)++] = va_arg(args, int);
	if (*count == 1024)
		write_buffer(buffer, count);
}

/**
 * handle_string - Handle the 's' specifier
 * @args: Argument
 * @buffer: A buffer
 * @count: Counter
 */
void handle_string(va_list args, char *buffer, int *count)
{
	int i;
	char *str = va_arg(args, char *);

	i = 0;

	while (str[i] != '\0')
	{
		buffer[(*count)++] = str[i++];
		if (*count == 1024)
			write_buffer(buffer, count);
	}
}

/**
 * handle_percent - Handle the '%%' specifier
 * @buffer: A buffer
 * @count: Counter
 */
void handle_percent(char *buffer, int *count)
{
	buffer[(*count)++] = '%';
	if (*count == 1024)
		write_buffer(buffer, count);
}



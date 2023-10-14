#include "main.h"

int _printf(const char *format, ...) {
    int count = 0;
    
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            switch (*(++format)) {
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
                    return -1;
            }
        } else {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

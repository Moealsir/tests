#include "main.h"
#include <unistd.h>
int _putchar(char c) 
{
    return (write(1, &c, 1));
}

int _puts(const char *s) 
{
    int count = 0;
    while (*s) {
        _putchar(*s);
        s++;
        count++;
    }
    return count;
}

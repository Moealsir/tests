#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
int _puts(const char *s);
int _printf(const char *format, ...);
int I_handle_d_specifier(int n);
int I_handle_b_specifier(int n);
int I_handle_i_specifier(int n);

int I_handle_u_specifier(unsigned int n);
int I_handle_o_specifier(unsigned int n);
int I_handle_x_specifier(unsigned int n);
int I_handle_X_specifier(unsigned int n);
#endif /* MAIN_H */

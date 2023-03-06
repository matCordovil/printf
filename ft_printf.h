#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int ft_printf(const char *formspec, ...);
int ft_print_c(char c);
int ft_print_di(int n);
int ft_print_p(unsigned long long p);
int ft_print_s(char *s);
int ft_print_u(unsigned int n);
int ft_print_xX(unsigned int n, const char xX);

#endif
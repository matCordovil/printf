#include "ft_printf.h"

int    ft_print_xX(unsigned int n, char formspec, int l)
{
    if (n >= 16)
    {
        l = ft_print_xX(n / 16, formspec, l);
        l = ft_print_xX(n % 16, formspec, l);
    }
    else
    {
        if (n < 10)
            ft_print_c(n + '0');
        else
        {
            if (formspec == 'x')
                ft_print_c(n - 10 + 'a');
            else
                ft_print_c(n - 10 + 'A');
        }
        l++;
    }
    return (l);
}
#include "ft_printf.h"

int ft_print_c(char c)
{
    return (write (1, &c, 1));
}

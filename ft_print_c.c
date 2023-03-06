#include "ft_printf.h"

int ft_print_c(char c)
{
    write (1, &c, 1);
    return (1);
}

int main()
{
    int count = ft_print_c('\n');
    printf("The ft_print_c of \\n returns: %d", count);
}
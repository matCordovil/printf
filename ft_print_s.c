# include "ft_printf.h"

static int ft_strlen(char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_print_s(char *s)
{
    if (!s)
        return (write(1, "NULL", 4));
    return (write(1, s, ft_strlen(s)));
}

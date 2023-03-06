# include "ft_printf.h"

int ft_strlen(char *s)
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
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

/*int main()
{
    int count = ft_print_s("hello\n");
    printf("The ft_print_s of hello returns: %d", count);
}*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int ft_print_c(char c)
{
    write (1, &c, 1);
    return (1);
}

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

int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	makepos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = numlen(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		len--;
		s[len] = makepos(n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int ft_print_di(int n)
{
    char    *s;
    int l;

    s = ft_itoa(n);
    l = ft_print_s(s);
    free(s);
    return (l);
}

int ft_printargms(va_list argms, const char formspec)
{
    if (formspec == 'c')
        return (ft_print_c(va_arg(argms, int)));
    else if (formspec == 'd' || formspec == 'i')
        return (ft_print_di(va_arg(argms, int)));
    /*else if (formspec == 'p')
        return (ft_print_p(va_arg(argms, unsigned long long)));*/
    else if (formspec == 's')
        return (ft_print_s(va_arg(argms, char *)));
    /*else if (formspec == 'u')
        return (ft_print_u(va_arg(argms, unsigned int)));
    else if (formspec == 'x' || formspec == 'X')
        return (ft_print_xX(va_arg(argms, unsigned int), formspec));*/
    else if (formspec == '%')
        return (ft_print_c('%'));
    return (0);
}

int ft_printf(const char *formspec, ...)
{
    va_list 	argms;
    int		ret_val;
    size_t  	i;

    if (!formspec)
        return (-42);
    va_start(argms, formspec);
    ret_val = 0;
    i = 0;
    while (formspec[i])
    {
        if (formspec[i] == '%')
        {
            ret_val += ft_printargms(argms, formspec[i + 1]);
            i++;
        }
        else
            ret_val += ft_print_c(formspec[i]);
        i++;
    }
    va_end(argms);
    return (ret_val);
}

int main(void)
{
    ft_printf(" The ft_printf of -658 returns: %d\n", ft_printf("%d", -658));
    ft_printf(" The ft_printf of 42 returns: %d\n", ft_printf("%i", 42));
    ft_printf(" The ft_printf of marvin returns: %d\n", ft_printf("%s", "marvin"));
    ft_printf(" The ft_printf of P returns: %d\n", ft_printf("%c", 'P'));
    ft_printf(" The ft_printf of %% returns: %d\n", ft_printf("%%"));
    return (0);
}
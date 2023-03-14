#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_print_c(char c) //done
{
    return (write (1, &c, 1));
}

static int ft_strlen(char *s) //done
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_print_s(char *s) //done
{
    if (!s)
        return (write(1, "NULL", 4));
    return (write(1, s, ft_strlen(s)));
}

static int	numlen(int n) //done
{
	size_t	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static int	makepos(int n) //done
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*ft_itoa(int n) //done
{
	size_t		l;
	char	*s;

	l = numlen(n);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--l] = makepos(n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int ft_print_di(int n) //done
{
    char    *s;
    int l;

    s = ft_itoa(n);
    l = ft_print_s(s);
    free(s);
    return (l);
}

/*static int	unslen(unsigned int n) //done
{
	size_t	l;

	l = 0;
	if (n == 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static char	*ft_utoa(unsigned int n) //done
{
	size_t		l;
	char	*s;

	l = unslen(n);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--l] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}*/

int ft_print_u(unsigned int n, int l)//done
{
    if (n >= 10)
    {
        l = ft_print_u(n / 10, l);
        l = ft_print_u(n % 10, l);
    }
    else
    {
        ft_print_c(n + '0');
        l++;
    }
    return (l);
}

int ft_print_xX(unsigned int n, char formspec, int l)//done
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

static int ft_printargms(va_list argms, const char formspec)
{
    if (formspec == 'c')
        return (ft_print_c(va_arg(argms, int)));
    else if (formspec == 's')
        return (ft_print_s(va_arg(argms, char *)));
    /*else if (formspec == 'p')
        return (ft_print_p(va_arg(argms, unsigned long long)));*/
    else if (formspec == 'd' || formspec == 'i')
        return (ft_print_di(va_arg(argms, int)));
    else if (formspec == 'u')
        return (ft_print_u(va_arg(argms, unsigned int), 0));
    else if (formspec == 'x' || formspec == 'X')
        return (ft_print_xX(va_arg(argms, unsigned int), formspec, 0));
    else if (formspec == '%')
        return (ft_print_c('%'));
    return (0);
}

int ft_printf(const char *formspec, ...)//done
{
    va_list 	argms;
    size_t		r;
    size_t  	i;

    if (!formspec)
        return (-42);
    va_start(argms, formspec);
    r = 0;
    i = 0;
    while (formspec[i])
    {
        if (formspec[i] == '%')
        {
            r += ft_printargms(argms, formspec[i + 1]);
            i++;
        }
        else
            r += ft_print_c(formspec[i]);
        i++;
    }
    va_end(argms);
    return (r);
}

int main(void)
{
    /*ft_printf(" printed with format %%c and the return is %d\n", ft_printf("%c", 'P'));
    ft_printf(" printed with format %%s and the return is %d\n", ft_printf("%s", "marvin"));
    ft_printf(" printed with format %%d and the return is %d\n", ft_printf("%d", -2147483648));
    ft_printf(" printed with format %%d and the return is %d\n", ft_printf("%d", 0));
    ft_printf(" printed with format %%i and the return is %d\n", ft_printf("%i", 2147483647));
    ft_printf(" printed with format %%u and the return is %d\n", ft_printf("%u", 4294967295));
    ft_printf(" printed with format %%u and the return is %d\n", ft_printf("%u", 0));
    ft_printf(" is 107 printed with format %%X and the return is %d\n", ft_printf("%X", 107));
    ft_printf(" is 255 printed with format %%x and the return is %d\n", ft_printf("%x", 255));
    ft_printf(" is 256 printed with format %%X and the return is %d\n", ft_printf("%X", 256));
    ft_printf(" is 13 printed with format %%X and the return is %d\n", ft_printf("%X", 13));
    ft_printf(" printed with format %%%% and the return is %d\n", ft_printf("%%"));*/
    printf("%x\n", -300);
    printf("%x\n", 300);
    printf("%x\n", 0);
    printf("%x\n", 17);
    return (0);
}

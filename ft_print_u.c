#include "ft_printf.h"

static int	unslen(unsigned int n)
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

static char	*ft_utoa(unsigned int n)
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
}

int ft_print_u(unsigned int n)
{
    char    *s;
    int l;

    s = ft_utoa(n);
    l = ft_print_s(s);
    free(s);
    return (l);
}
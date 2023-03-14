#include "ft_printf.h"

static int	numlen(int n)
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

static int	makepos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*ft_itoa(int n)
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

int ft_print_di(int n)
{
    char    *s;
    int l;

    s = ft_itoa(n);
    l = ft_print_s(s);
    free(s);
    return (l);
}

/*int main()
{
    int count = ft_print_di(-658);
    printf("The ft_print_s of -658 returns: %i", count);
}*/
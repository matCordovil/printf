#include "ft_printf.h"

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

/*int main()
{
    int count = ft_print_di(-658);
    printf("The ft_print_s of -658 returns: %i", count);
}*/
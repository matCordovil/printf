/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:55:35 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/14 19:55:37 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printargms(va_list argms, const char formspec)
{
	if (formspec == 'c')
		return (ft_print_c(va_arg(argms, int)));
	else if (formspec == 's')
		return (ft_print_s(va_arg(argms, char *)));
	else if (formspec == 'p')
		return (ft_print_p(va_arg(argms, unsigned long long)));
	else if (formspec == 'd' || formspec == 'i')
		return (ft_print_di(va_arg(argms, int)));
	else if (formspec == 'u')
		return (ft_print_u(va_arg(argms, unsigned long long), 0));
	else if (formspec == 'x' || formspec == 'X')
		return (ft_print_xx(va_arg(argms, unsigned int), formspec, 0));
	else if (formspec == '%')
		return (ft_print_c('%'));
	return (0);
}

int	ft_printf(const char *formspec, ...)
{
	va_list		argms;
	size_t		r;
	size_t		i;

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

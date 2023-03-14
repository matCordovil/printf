/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:55:20 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/14 19:55:22 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xx(unsigned long long n, char formspec, int l)
{
	if (n >= 16)
	{
		l = ft_print_xx(n / 16, formspec, l);
		l = ft_print_xx(n % 16, formspec, l);
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

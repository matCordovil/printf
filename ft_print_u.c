/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:55:14 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/14 19:55:16 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned long long n, int l)
{
	if (n >= 10)
	{
		l = ft_print_u(n / 10, l);
		l = ft_print_u(n % 10, l);
	}
	else
		l += ft_print_c(n + '0');
	return (l);
}

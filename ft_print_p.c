/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:54:48 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/14 19:54:52 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long long p)
{
	if (p == 0)
		return (write (1, "(nil)", 5));
	return (write (1, "0x", 2) + ft_print_xx(p, 'x', 0));
}

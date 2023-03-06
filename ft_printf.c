/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluffy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:47:01 by fluffy            #+#    #+#             */
/*   Updated: 2023/03/06 19:47:11 by fluffy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printargms(va_list argms, const char formspec)
{
    if (formspec == 'c')
        return (ft_print_c(va_arg(argms, int)));
    else if (formspec == 'd' || formspec == 'i')
        return (ft_print_di(va_arg(argms, int)));
    else if (formspec == 'p')
        return (ft_print_p(va_arg(argms, unsigned long long)));
    else if (formspec == 's')
        return (ft_print_s(va_arg(argms, char *)));
    else if (formspec == 'u')
        return (ft_print_u(va_arg(argms, unsigned int)));
    else if (formspec == 'x' || formspec == 'X')
        return (ft_print_xX(va_arg(argms, unsigned int), formspec));
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

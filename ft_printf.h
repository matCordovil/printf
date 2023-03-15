/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:56:02 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/14 20:09:23 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(unsigned long long p);
int	ft_print_di(int n);
int	ft_print_u(unsigned int n, int l);
int	ft_print_xx(unsigned long long n, char formspec, int l);
int	ft_printf(const char *formspec, ...);

#endif

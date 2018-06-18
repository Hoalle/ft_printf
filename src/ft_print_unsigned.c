/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:58 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 14:39:32 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	char	*ft_s_print_u(va_list ap, char car, char flags)
{
	unsigned long int		lgc;
	unsigned long long int	llgc;
	unsigned short int		shc;
	char					*str;
	unsigned int			c;

	if ((car == 'U' || flags == 'l' || flags == 'j' || (car == 'U' &&
					flags == 'h')) && flags != 'H')
	{
		lgc = va_arg(ap, unsigned long int);
		str = ft_long_utoa(lgc);
	}
	if ((flags == 'L' || flags == 'z') && car != 'U')
	{
		llgc = va_arg(ap, unsigned long long int);
		str = ft_longlong_utoa(llgc);
	}
	if (((flags == 'h') && car != 'U') || (car == 'U' && flags == 'H'))
	{
		shc = va_arg(ap, int);
		str = ft_short_utoa(shc);
	}
	if (flags == 'H' && car != 'U')
	{
		c = va_arg(ap, unsigned int);
		str = ft_char_utoa(c);
	}
	return (str);
}

int				ft_print_unsigned(va_list ap, char car, char *arg, char flags)
{
	char					*str;
	unsigned int			c;

	if (car == 'u' && flags != 'H' && flags != 'h' && flags != 'l' &&
	flags != 'L' && flags != 'j' && flags != 'z')
	{
		c = va_arg(ap, unsigned int);
		str = ft_utoa(c);
	}
	else
		str = ft_s_print_u(ap, car, flags);
	ft_prec_min_oxu(0, ft_strlen(str), arg, 'u');
	c = 0;
	if (ft_strcmp(str, "0") == 0 && g_prec == '.' && g_zero != '0')
		c = 1;
	if (c == 0)
		ft_putstr(str);
	ft_no_prec(str, 0, 0);
	if (c == 1)
		c = ft_len_ret2();
	else
		c = ft_strlen(str) + ft_len_ret_nbr(0, (int)ft_strlen(str));
	free(str);
	return (c);
}

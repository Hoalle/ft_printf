/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:49 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/07 17:36:27 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_print_p(va_list ap, char *arg)
{
	char			*str;
	unsigned long	c;
	int				ret;

	c = va_arg(ap, unsigned long);
	str = ft_long_htoa(c, 97);
	if (g_zero == '0')
		ft_putstr("0x");
	ft_prec_min_oxu(0, ft_strlen(str) + 2, arg, 'p');
	if (g_zero != '0')
		ft_putstr("0x");
	ft_putstr(str);
	c = 2;
	if (g_noprec == '-' && g_minfd >= ((int)ft_strlen(str) + 2))
	{
		c = g_minfd - ft_strlen(str) - c;
		while (c--)
			ft_putchar(' ');
	}
	ret = ft_strlen(str) + ft_len_ret_nbr(0, (int)ft_strlen(str) + 2);
	free(str);
	return (2 + ret);
}

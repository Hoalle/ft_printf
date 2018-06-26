/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_min_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:11 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/13 16:11:20 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_prec_min_p_s(char *str)
{
	int tmp;
	int len;
	int ret;

	tmp = 0;
	len = ft_strlen(str);
	if (g_p < g_minfd)
	{
		ft_putstr("0x");
		tmp = g_minfd - len;
		if (tmp < 0)
			tmp = 0;
			ret = 2 + tmp + len;
		while(tmp--)
			ft_putchar('0');
		ft_putstr(str);
	}
	if (g_p > g_minfd)
	{
		tmp = g_p - g_minfd - 2;
		while (tmp--)
			ft_putchar(' ');
		ft_putstr("0x");
		tmp = g_minfd - len;
		if (tmp < 0)
			tmp = 0;
		ret = tmp + 2 + len + (g_p - g_minfd);
		while (tmp--)
			ft_putchar('0');
		ft_putstr(str);
	}
	return (ret);
}

int		ft_prec_min_p(char *arg, char *str)
{
	int len;
	int c;
	int ret;

	c = 2;
	len = ft_strlen(str);
	if (g_prec != '.' || (g_prec == '.' && g_p > g_minfd && g_minfd < len &&
	g_p > len) || (g_p == 0 && g_prec == '.' && g_minfd == 0))
	{
		if (g_zero == '0')
			ft_putstr("0x");
		ft_prec_min_oxu(0, ft_strlen(str) + 2, arg, 'p');
		if (g_zero != '0')
			ft_putstr("0x");
		ft_putstr(str);
		if (g_noprec == '-' && g_minfd >= ((int)ft_strlen(str) + 2))
		{
			c = g_minfd - ft_strlen(str) - c;
			while (c--)
				ft_putchar(' ');
		}
		ret = ft_strlen(str) + 2 + ft_len_ret_nbr(0, len + 2);
	}
	else
		ret = ft_prec_min_p_s(str);
	return (ret);
}

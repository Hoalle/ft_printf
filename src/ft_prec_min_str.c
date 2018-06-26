/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_min_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:20 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 15:33:35 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_precision_str(int len, char *str)
{
	int lenp;
	int i;

	i = 0;
	if (g_p > g_minfd || (g_p < g_minfd && g_minfd > len && g_p > len))
	{
		if (g_noprec != '-')
		{
			if (g_minfd > len)
				lenp = g_p - len;
			if (g_minfd < len)
				lenp = g_p - g_minfd;
			while (lenp--)
				ft_putchar(' ');
		}
	}
	if (g_minfd < len)
	{
		len = g_minfd;
		while (len--)
			ft_putchar(str[i++]);
		return (1);
	}
	return (0);
}

static int		ft_zero_str()
{
	int tmp;

	if (g_p > g_minfd)
	{
		tmp = g_p - 1;
		while (tmp--)
			ft_putchar('0');
	}
	return (0);
}

int				ft_prec_min_str(int len, char *str)
{
	int ret;

	ret = 0;
	if (g_prec == '.' && g_noprec != '-' && g_zero != '0')
	{
		ret = ft_precision_str(len, str);
	}
	if (g_prec == '.' && g_zero == '0')
		ft_zero_str();
	if (g_prec != '.' && g_noprec != '-' && len < g_minfd)
	{
		len = g_minfd - len;
		if (g_zero != '0')
		{
			while (len--)
				ft_putchar(' ');
		}
		else
		{
			while (len--)
				ft_putchar('0');
		}
	}
	return (ret);
}

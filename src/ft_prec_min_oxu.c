/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_min_oxu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:16 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/07 16:14:25 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_flags_hexa(char *arg, char car)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '#')
		{
			if (car == 'x' || car == 'p')
				ft_putstr("0x");
			if (car == 'X')
				ft_putstr("0X");
			return (1);
		}
		i++;
	}
	return (0);
}

static	int		ft_preci_s(int flags, char *arg, char car, int len)
{
	int c;

	c = 0;
	if (flags == 4)
		c = 2;
	if (g_noprec != '-' && flags != 2 && g_p >= g_minfd + c)
	{
		if (g_minfd < len)
			c = c + len - g_minfd;
		c = (g_p - g_minfd) - c;
		if (c < 0)
			c = 0;
		while (c--)
			ft_putchar(' ');
	}
	if (flags == 4)
		c = ft_flags_hexa(arg, car);
	if (g_minfd >= len)
	{
		len = g_minfd - len;
		while (len--)
			ft_putchar('0');
	}
	return (c);
}

static int		ft_precision_oxu(char *arg, int len, int flags, char car)
{
	int ret;

	ret = 0;
	if (g_p > g_minfd)
		ret = ft_preci_s(flags, arg, car, len);
	if (g_p <= g_minfd && g_minfd >= len)
	{
		if (flags == 4)
		{
			ft_putchar('0');
			ft_putchar(car);
		}
		ret = 1;
		len = g_minfd - len;
		while (len--)
			ft_putchar('0');
	}
	return (ret);
}

static	int		ft_minfd_oxu(int len, int flags, char car)
{
	int ret;

	ret = 0;
	if (g_noprec != '-' && len < g_minfd)
	{
		if (flags == 4)
			len = len + 2;
		len = g_minfd - len;
		if (g_zero == '0')
		{
			if (flags == 4)
			{
				ft_putchar('0');
				ft_putchar(car);
				ret = 1;
			}
			while (len--)
				ft_putchar('0');
			return (ret);
		}
		while (len--)
			ft_putchar(' ');
	}
	return (0);
}

int				ft_prec_min_oxu(int flags, int len, char *arg, char car)
{
	int ret;

	ret = 0;
	if (flags == 1)
		len++;
	if (g_prec == '.')
	{
		ret = ft_precision_oxu(arg, len, flags, car);
	}
	if (g_prec != '.')
	{
		ret = ft_minfd_oxu(len, flags, car);
	}
	return (ret);
}

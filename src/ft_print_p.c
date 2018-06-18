/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:49 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 17:43:13 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_ss_1_p()
{
	int tmp;

	if (g_p > 1 && g_minfd == 0 && g_noprec != '-')
	{
		tmp = g_p - 2;
		while (tmp--)
			ft_putchar(' ');
	}
	if (g_minfd != 0)
	{
		tmp = g_minfd;
		while (tmp--)
			ft_putchar('0');
	}
}

static void	ft_no_precs1()
{
	int tmp;
	if (g_p > 1 && g_minfd == 0 && g_prec == '.')
	{
		tmp = g_p - 2;
		while (tmp--)
			ft_putchar(' ');
	}
	if (g_prec != '.' && g_minfd > 2)
	{
		tmp = g_minfd - 3;
		while (tmp--)
			ft_putchar(' ');
	}
}

static int	ft_s_1_p()
{
	int ret;
	int tmp;

	ret = 0;
	if ((g_p == 0 && g_minfd == 0) || (g_prec == '.' && g_minfd != 0))
		ft_putstr("0x");
	if (g_prec == '.')
		ft_ss_1_p();
	if (g_prec != '.' && g_minfd > 2 && g_noprec != '-')
	{
		tmp = g_minfd - 3;
		while (tmp--)
			ft_putchar(' ');
	}
	if ((g_prec == '.' && g_minfd == 0 && g_p != 0) || (g_prec != '.' && g_minfd
				!= 0))
		ft_putstr("0x");
	if (g_prec != '.')
		ft_putchar('0');
	if (g_noprec == '-')
		ft_no_precs1();
	ret = ft_ret_s1();
	return (ret);
}

static int	ft_s_2_p(char *str, char *arg)
{
	int c;

	c = 2;
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
	return (0);
}

int			ft_print_p(va_list ap, char *arg)
{
	char			*str;
	unsigned long	c;
	int				ret;
	int x;

	x = 1;
	c = va_arg(ap, unsigned long);
	str = ft_long_htoa(c, 97);
	if (ft_strcmp(str, "0") == 0)
	{
		x = 1;
		ret = ft_s_1_p();
	}
	else
	{
		x = 2;
		ft_s_2_p(str, arg);
		ret = ft_strlen(str) + x + ft_len_ret_nbr(0, (int)ft_strlen(str) + 2);
	}
	free(str);
	return (ret);
}

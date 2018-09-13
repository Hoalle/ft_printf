/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:49 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/13 17:42:31 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_ss_1_p(void)
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

static void		ft_no_precs1(void)
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

static int		ft_gzero(void)
{
	int tmp;
	int ret;

	tmp = g_minfd - 2;
	ft_putstr("0x");
	while (tmp--)
		ft_putchar('0');
	ret = ft_ret_s1();
	return (ret);
}

static int		ft_s_1_p(void)
{
	int ret;
	int tmp;

	ret = 0;
	if (g_zero == '0' && g_minfd != 0 && g_prec != '.')
		return (ft_gzero());
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

int				ft_print_p(va_list ap, char *arg)
{
	char			*str;
	unsigned long	c;
	int				ret;

	c = va_arg(ap, unsigned long);
	str = ft_long_htoa(c, 97);
	if (ft_strcmp(str, "0") == 0)
		ret = ft_s_1_p();
	else
		ret = ft_prec_min_p(arg, str);
	free(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:00 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 12:32:55 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_check_flags_nbr(char *arg)
{
	int sign;
	int sp;
	int i;

	sign = 0;
	i = 0;
	sp = 0;
	while (arg[i])
	{
		if (arg[i] == '+')
			sign = 1;
		if (arg[i] == ' ')
			sp = 1;
		i++;
	}
	if (sp == 1 && sign == 1)
		return (3);
	if (sign == 1)
		return (1);
	if (sp == 1)
		return (2);
	return (0);
}

static int		ft_s_len_ret(int lenbr)
{
	if (g_prec == '.')
	{
		if ((g_minfd == 0 && g_p == 0) || (g_minfd >= lenbr && g_p <= lenbr))
			return (lenbr);
		if (g_minfd < lenbr && g_p < g_minfd)
			return (g_minfd);
		if (g_p > g_minfd || (g_p < g_minfd && g_minfd > lenbr))
			return (g_p);
		if (g_p <= lenbr && g_minfd > lenbr)
			return (lenbr);
	}
	else if (g_prec != '.')
	{
		if (g_minfd >= lenbr)
			return (g_minfd);
		else
			return (lenbr);
	}
	return (0);
}

int				ft_len_ret_nbr(int nbflags, int lenbr)
{
	int c;

	c = 0;
	if (nbflags == 7 && ft_s_len_ret(lenbr) != 0)
		return (ft_s_len_ret(lenbr));
	else if (nbflags == 8 && g_prec == '.' && g_p >= 1)
		c = g_p - 1;
	else if (nbflags == 8 && (g_p == 0 && (g_prec == '.' || g_minfd == 0)))
		c = 0;
	else if (g_minfd != 0 && g_p == 0 && g_minfd >= lenbr && nbflags != 7)
		c = g_minfd - lenbr;
	else if ((g_minfd == 0 || g_minfd < lenbr) && nbflags == 4 && g_p == 0)
		c = 2;
	else if ((g_minfd == 0 || g_minfd < lenbr) && nbflags != 0 && nbflags != 4
			&& g_p == 0 && nbflags != 7)
		c = 1;
	else if (g_minfd != 0 && g_p != 0 && g_p > g_minfd && nbflags != 7 &&
			g_p >= lenbr)
		c = g_p - lenbr;
	else if (g_minfd != 0 && g_p != 0 && g_p < g_minfd && g_minfd > lenbr &&
			nbflags != 7)
		c = g_minfd - lenbr;
	else if (g_p > g_minfd && g_p > lenbr && g_minfd < lenbr)
		c = g_p - lenbr;
	return (c);
}

int				ft_write_flags_nbr(int flags, char *nbr)
{
	if (flags == 3 || flags == 1)
	{
		if (nbr[0] != '-')
			ft_putchar('+');
		if (nbr[0] == '-')
		{
			ft_putchar('-');
			return (1);
		}
		return (0);
	}
	if (flags == 2)
	{
		if (nbr[0] != '-')
			ft_putchar(' ');
		if (nbr[0] == '-')
		{
			ft_putchar('-');
			return (1);
		}
		return (0);
	}
	return (0);
}

void			ft_no_prec(char *nbr, int nbflags, int c)
{
	int len;

	len = ft_strlen(nbr);
	if (g_noprec == '-' && g_minfd >= len && g_p == 0)
		c = c + g_minfd - ft_strlen(nbr);
	else if (g_noprec == '-' && g_minfd >= len && g_p >= g_minfd)
		c = c + g_p - g_minfd;
	else if (g_noprec == '-' && g_p >= len && g_minfd < len)
		c = c + g_p - len;
	if (nbflags != 0)
		c--;
	if (g_noprec == '-')
	{
		while (c--)
			ft_putchar(' ');
	}
}

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

static	int		ft_minfd_nbr_s(int len, int nbflags, char *nbr, int neg)
{
	neg = ft_write_flags_nbr(nbflags, nbr);
	if (neg == 1)
		len++;
	if (neg == 0 && nbr[0] == '-')
	{
		ft_putchar('-');
		neg = 1;
	}
	while (len--)
		ft_putchar('0');
	return (neg);
}

int				ft_minfd_nbr(int len, int nbflags, char *nbr)
{
	int neg;

	neg = 0;
	if (g_minfd >= len)
	{
		len = g_minfd - len;
		if (g_zero == '0' && g_noprec != '-')
		{
			neg = ft_minfd_nbr_s(len, nbflags, nbr, neg);
			return (neg);
		}
		if (g_noprec != '-')
		{
			while (len--)
				ft_putchar(' ');
			if (nbr[0] == '-' && nbflags != 0)
				ft_putchar(' ');
		}
	}
	neg = ft_write_flags_nbr(nbflags, nbr);
	return (neg);
}

static	int		ft_pn_s(char *nbr, int flg, int nbf, int neg)
{
	int len;

	len = ft_strlen(nbr);
	if (nbr[0] == '-' && flg == 0)
		flg = 1;
	flg = g_p - flg - g_minfd;
	if (g_noprec != '-')
	{
		while (flg--)
			ft_putchar(' ');
	}
	neg = ft_write_flags_nbr(nbf, nbr);
	if (neg == 1 && nbr[0] == '-')
		len--;
	if (neg == 0 && nbr[0] == '-')
	{
		neg = 1;
		ft_putchar('-');
		len--;
	}
	len = g_minfd - len;
	while (len--)
		ft_putchar('0');
	return (neg);
}

static int		ft_pn_s2(int flags, int len, int nbflags, char *nbr)
{
	int neg;

	neg = 0;
	flags = g_p - len;
	if (flags < 0)
		flags = 0;
	if (nbflags != 0)
		flags--;
	if (g_noprec != '-')
	{
		while (flags--)
			ft_putchar(' ');
	}
	neg = ft_write_flags_nbr(nbflags, nbr);
	return (neg);
}

int				ft_prec_nbr(int flags, int nbflags, char *nbr, int c)
{
	int neg;
	int len;

	len = ft_strlen(nbr);
	neg = 0;
	if (c == 1)
		return (ft_s_nolen());
	if (g_p > g_minfd && g_minfd >= len)
		neg = ft_pn_s(nbr, flags, nbflags, neg);
	if (g_p > g_minfd && g_minfd < len)
		neg = ft_pn_s2(flags, len, nbflags, nbr);
	if (g_p <= g_minfd && g_minfd >= len)
	{
		neg = ft_write_flags_nbr(nbflags, nbr);
		if (nbr[0] == '-')
		{
			len--;
			ft_putchar('-');
			neg = 1;
		}
		len = g_minfd - len;
		while (len--)
			ft_putchar('0');
	}
	return (neg);
}

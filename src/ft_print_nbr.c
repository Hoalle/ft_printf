/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:41 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 15:47:36 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_nbr_prec_min(char *nbr, int nbflags, int c)
{
	int neg;

	neg = 0;
	if (g_minfd == 0 && g_p == 0)
		return (neg = ft_write_flags_nbr(nbflags, nbr));
	if (c == 1)
		neg = ft_prec_nbr(0, 0, nbr, 1);
	if (nbflags != 0 && c != 1)
	{
		if (g_prec != '.')
			neg = ft_minfd_nbr(ft_strlen(nbr) + 1, nbflags, nbr);
		if (g_prec == '.')
			neg = ft_prec_nbr(1, nbflags, nbr, 0);
	}
	else if (nbflags == 0 && c != 1)
	{
		if (g_prec != '.')
			neg = ft_minfd_nbr(ft_strlen(nbr), 0, nbr);
		if (g_prec == '.')
			neg = ft_prec_nbr(0, 0, nbr, 0);
	}
	if (g_p > g_minfd && g_minfd > (int)ft_strlen(nbr) && neg == 1)
		neg = 2;
	return (neg);
}

static	char	*ft_nbr_neg(char *nbr)
{
	char	*newnbr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	newnbr = (char*)malloc(sizeof(char) * ft_strlen(nbr));
	if (nbr[0] == '-')
	{
		while (nbr[i])
		{
			newnbr[j] = nbr[i];
			i++;
			j++;
		}
		newnbr[j] = '\0';
		return (newnbr);
	}
	return (nbr);
}

static	char	*ft_s_print_nbr2(va_list ap, char flags, char *nbr, char car)
{
	long int	lgc;
	int			c;

	if ((car == 'd' || car == 'i') && flags != 'h' && flags != 'l' && flags !=
			'L' && flags != 'z' && flags != 'j' && flags != 'H')
	{
		c = va_arg(ap, int);
		nbr = ft_itoa(c);
	}
	if ((car == 'D' || flags == 'l' || flags == 'j' || flags == 'z' || (car ==
					'D' && flags == 'H')) &&
					flags != 'L')
	{
		lgc = va_arg(ap, long int);
		nbr = ft_long_itoa(lgc);
	}
	if (flags == 'H' && flags != 'l' && car != 'D')
	{
		c = va_arg(ap, int);
		nbr = ft_char_itoa(c);
	}
	return (nbr);
}

static	char	*ft_suite_print_nbr(va_list ap, char flags, char *nbr, char car)
{
	long long int	llgc;
	short int		shc;

	if (flags != 'L' && flags != 'h')
		nbr = ft_s_print_nbr2(ap, flags, nbr, car);
	if (flags == 'L')
	{
		llgc = va_arg(ap, long long int);
		nbr = ft_longlong_itoa(llgc);
	}
	if (flags == 'h')
	{
		shc = va_arg(ap, int);
		nbr = ft_short_itoa(shc);
	}
	return (nbr);
}

int				ft_print_nbr(va_list ap, char car, char flags, char *arg)
{
	char	*nbr;
	int		nbflags;
	int		c;

	nbr = NULL;
	car = ft_l_nbr(arg, car, flags);
	nbflags = ft_check_flags_nbr(arg);
	nbr = ft_suite_print_nbr(ap, flags, nbr, car);
	c = 0;
	if (ft_strcmp(nbr, "0") == 0 && g_prec == '.' && g_zero != '0')
		c = 1;
	car = ft_nbr_prec_min(nbr, nbflags, c);
	if (car == 1 || car == 2)
		nbr = ft_nbr_neg(nbr);
	if (c != 1)
		ft_putstr(nbr);
	ft_no_prec(nbr, nbflags, 0);
	if (c == 1)
		c = ft_len_ret2();
	else
		c = ft_strlen(nbr) + ft_len_ret_nbr(nbflags, (int)ft_strlen(nbr));
	if (car == 1 && nbflags == 0 && g_zero != '0')
		c++;
	free(nbr);
	return (c);
}

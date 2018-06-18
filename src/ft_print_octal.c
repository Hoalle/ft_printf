/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:45 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/15 15:51:24 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_check_flags_octal(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

static void		ft_s2_o(char f2, va_list ap, char car, char **str)
{
	unsigned long long int	llgc;
	unsigned long int		lgc;

	lgc = 0;
	llgc = 0;
	if (f2 == 'h' || f2 == 'z' || f2 == 'L')
	{
		llgc = va_arg(ap, unsigned long long int);
		*str = ft_longlong_otoa(llgc);
	}
	else if (car == 'O' || f2 == 'l' || f2 == 'j')
	{
		lgc = va_arg(ap, unsigned long int);
		*str = ft_long_otoa(lgc);
	}
}

static char		*ft_s_o(char f2, va_list ap, char car, unsigned int *c)
{
	char					*str;

	str = "\0";
	if ((car == 'o') && f2 != 'l' && f2 != 'L' && f2 != 'h' && f2
			!= 'j' && f2 != 'z' && f2 != 'H')
	{
		*c = va_arg(ap, unsigned int);
		str = ft_otoa(*c);
	}
	else if (f2 == 'H' && car != 'O')
	{
		*c = va_arg(ap, unsigned int);
		str = ft_char_otoa(*c);
	}
	else if (car == 'O' || f2 == 'h' || f2 == 'z' || f2 == 'L' || f2 == 'l' ||
			f2 == 'j')
		ft_s2_o(f2, ap, car, &str);
	return (str);
}

static	int		ft_s_p_octal(int flags, char *str, char *arg, unsigned int *c)
{
	ft_prec_min_oxu(flags, ft_strlen(str), arg, 'o');
	if (*c != 0)
		*c = ft_write_flags_octal(arg);
	ft_putstr(str);
	ft_no_prec(str, 0, *c);
	if (ft_strcmp(str, "0") == 0 && flags == 1)
		flags = 0;
	flags = ft_strlen(str) + ft_len_ret_nbr(flags, (int)ft_strlen(str));
	return (flags);
}

int				ft_print_octal(va_list ap, char car, char *arg, char flags2)
{
	char				*str;
	unsigned int		c;
	int					flags;
	int					nb;

	flags = ft_check_flags_octal(arg);
	c = 1;
	str = ft_s_o(flags2, ap, car, &c);
	if (ft_strcmp(str, "0") == 0)
		c = 0;
	nb = 0;
	if (ft_strcmp(str, "0") == 0 && g_prec == '.' && g_zero != '0' &&
			flags != 1)
		nb = 1;
	if (nb == 0)
		flags = ft_s_p_octal(flags, str, arg, &c);
	else if (nb == 1)
	{
		ft_prec_min_oxu(0, 0, NULL, 'o');
		flags = ft_len_ret2();
	}
	if (str != NULL)
		free(str);
	return (flags);
}

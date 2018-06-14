/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:54 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 12:52:25 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	ft_noprec_str(int len)
{
	int c;

	c = 0;
	if (g_prec == '.')
	{
		if (g_p > g_minfd && g_minfd < len)
			c = g_p - g_minfd;
		if (g_p > g_minfd && g_minfd > len)
			c = g_p - len;
	}
	else
	{
		if (g_minfd >= len)
			c = g_minfd - len;
	}
	while (c--)
		ft_putchar(' ');
}

int				ft_print_str(va_list ap, char car)
{
	char	*str;
	int		write;
	int		c;

	c = 0;
	str = (char*)malloc(sizeof(char));
	if (car == 's')
	{
		str = va_arg(ap, char*);
		if (str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		write = ft_prec_min_str(ft_strlen(str), str);
		if (write != 1)
			ft_putstr(str);
	}
	if (g_noprec == '-')
		ft_noprec_str(ft_strlen(str));
	c = ft_len_ret_nbr(7, (int)ft_strlen(str));

	return (c);
}

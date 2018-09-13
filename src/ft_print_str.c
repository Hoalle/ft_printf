/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:54 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/13 17:33:58 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	ft_g_prec_s(int len, int *x, int *y)
{
	if (g_minfd > len && g_p > len)
	{
		*x = len;
		*y = g_p - len;
	}
	if (g_minfd < len && g_p < len)
	{
		if (g_minfd < g_p)
		{
			*x = g_minfd;
			*y = g_p - g_minfd;
		}
		if (g_minfd > g_p)
		{
			*x = g_minfd;
			*y = 0;
		}
	}
}

static	void	ft_g_prec(int len, char *str, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if ((g_minfd > len && g_p > len) | (g_minfd < len && g_p < len))
		ft_g_prec_s(len, &x, &y);
	if (g_minfd < len && g_p > len)
	{
		x = g_minfd;
		y = g_p - g_minfd;
	}
	if (g_minfd > len && g_p < len)
	{
		x = len;
		y = 0;
	}
	while (x--)
		ft_putchar(str[i++]);
	while (y--)
		ft_putchar(' ');
}

static	void	ft_noprec_str(int len, char *str)
{
	int c;
	int i;

	c = 0;
	i = 0;
	if (g_prec == '.')
		ft_g_prec(len, str, i);
	else
	{
		ft_putstr(str);
		if (g_minfd >= len)
			c = g_minfd - len;
		while (c--)
			ft_putchar(' ');
	}
}

static int		ft_print_str_s(char *str)
{
	int write;

	if (str == NULL && g_minfd == 0 && g_p == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (str == NULL)
		str = "0";
	write = ft_prec_min_str(ft_strlen(str), str);
	if (write != 1 && g_noprec != '-' && str != NULL)
		ft_putstr(str);
	return (0);
}

int				ft_print_str(va_list ap, char car)
{
	char	*str;
	int		c;
	wchar_t *wstr;

	c = 0;
	str = (char*)malloc(sizeof(char));
	if (car == 's')
	{
		str = va_arg(ap, char*);
		if (ft_print_str_s(str) == 6)
			return (6);
	}
	if (car == 'S')
	{
		wstr = va_arg(ap, wchar_t*);
		if (wstr == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	if (g_noprec == '-')
		ft_noprec_str(ft_strlen(str), str);
	c = ft_len_ret_nbr(7, (int)ft_strlen(str));
	return (c);
}

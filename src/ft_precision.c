/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:25 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 15:37:57 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_check_star2(char *arg, int i, va_list ap, int k)
{
	if (k == 1)
	{
		i = 0;
		while (arg[i])
		{
			if (arg[i] == '*')
			{
				g_prec = '.';
				g_p = va_arg(ap, int);
				return (2);
			}
			i++;
		}
	}
	if (k == 2)
	{
		g_minfd = va_arg(ap, int);
		if (g_minfd < 0)
		{
			g_noprec = '-';
			g_minfd = g_minfd * -1;
		}
	}
	return (0);
}

static int		ft_check_star(va_list ap, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			if (ft_check_star2(arg, i, ap, 1) == 2)
				return (2);
		}
		i++;
	}
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '*')
		{
			ft_check_star2(arg, i, ap, 2);
			return (1);
		}
		i++;
	}
	return (0);
}

static int		ft_star_2(char *arg)
{
	int		i;
	int		j;
	char	*nb;

	j = 0;
	i = 0;
	nb = (char*)malloc(sizeof(char));
	while (arg[i] != '.')
		i++;
	i++;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		nb[j] = arg[i];
		i++;
		j++;
	}
	nb[j] = '\0';
	g_minfd = ft_atoi(nb);
	free(nb);
	return (0);
}

int				ft_precision(va_list ap, char *arg)
{
	int		i;
	int		j;
	int		star;

	i = 0;
	j = 0;
	if ((star = ft_check_star(ap, arg)) == 1)
		return (0);
	if (star == 2)
	{
		ft_star_2(arg);
		while (arg[i])
		{
			if (arg[i++] == '-')
				g_noprec = '-';
		}
		return (0);
	}
	ft_precision2(arg);
	return (0);
}

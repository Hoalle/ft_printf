/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:33:10 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 12:36:26 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_reset(void)
{
	g_minfd = 0;
	g_noprec = '\0';
	g_prec = '\0';
	g_p = 0;
	g_zero = '\0';
}

int				ft_s_nolen(void)
{
	int tmp;

	if (g_p != 0 && g_minfd == 0)
	{
		tmp = g_p;
		while (tmp--)
			ft_putchar(' ');
	}
	else if (g_p > g_minfd)
	{
		tmp = g_p - g_minfd;
		while (tmp--)
			ft_putchar(' ');
		tmp = g_minfd;
		while (tmp--)
			ft_putchar('0');
	}
	if (g_p < g_minfd)
	{
		tmp = g_minfd;
		while (tmp--)
			ft_putchar('0');
	}
	return (0);
}

int				ft_len_ret2(void)
{
	if (g_p != 0 && g_minfd == 0)
		return (g_p);
	else if (g_p > g_minfd)
		return (g_p);
	else if (g_p < g_minfd)
		return (g_minfd);
	return (0);
}

char			ft_l_nbr(char *arg, char car, char flags)
{
	int i;

	i = 0;
	if (flags != 'l' && flags != 'L')
	{
		while (arg[i])
		{
			if (arg[i] == 'l')
			{
				if (car == 'd')
				{
					car = 'D';
					return (car);
				}
			}
			i++;
		}
	}
	return (car);
}

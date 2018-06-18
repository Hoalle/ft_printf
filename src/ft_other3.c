/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:57:39 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 14:07:55 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

int				ft_write_flags_octal(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '#')
		{
			ft_putchar('0');
			return (-1);
		}
		i++;
	}
	return (0);
}

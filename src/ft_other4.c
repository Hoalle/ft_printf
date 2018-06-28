/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:43:57 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/28 14:45:07 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_check_flags_hexa(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '#')
			return (4);
		i++;
	}
	return (0);
}

int		ft_flags_hexa(char *arg, char car)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '#')
		{
			if (car == 'x')
				ft_putstr("0x");
			if (car == 'X')
				ft_putstr("0X");
			return (2);
		}
		i++;
	}
	return (0);
}

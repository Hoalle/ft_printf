/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:09:42 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/13 15:33:11 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		ft_check_flags_s(char *arg, char str, int i)
{
	if (arg[i] == 'l')
	{
		if (arg[i + 1] == 'l')
			str = 'L';
		else
			str = 'l';
		return (str);
	}
	if (arg[i] == 'j')
		str = 'j';
	if (arg[i] == 'z')
		str = 'z';
	return (str);
}

char			ft_check_flags(char *arg)
{
	char	str;
	int		i;

	i = 0;
	str = '\0';
	while (arg[i])
	{
		if (arg[i] == 'h')
		{
			if (arg[i + 1] == 'h')
				str = 'H';
			else
				str = 'h';
			return (str);
		}
		if (arg[i] == 'l' || arg[i] == 'j' || arg[i] == 'z')
		{
			str = ft_check_flags_s(arg, str, i);
			return (str);
		}
		i++;
	}
	return (str);
}

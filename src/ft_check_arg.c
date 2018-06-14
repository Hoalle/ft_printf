/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Start_Condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:00:11 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/13 17:38:00 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_copy(char *f, int i)
{
	int		len;
	int		tmp;
	char	*str;

	len = 0;
	tmp = i;
	while (f[i] != 'c' && f[i] != 'C' && f[i] != 'd' && f[i] != 'D' &&
	f[i] != 'i' && f[i] != 's' && f[i] != 'S' && f[i] != 'p' && f[i] != 'o' &&
	f[i] != 'O' && f[i] != 'u' && f[i] != 'U' && f[i] != 'x' && f[i] != 'X' &&
	f[i++] != '%')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len + 1] = '\0';
	i = tmp;
	tmp = 0;
	while (tmp <= len)
	{
		str[tmp] = f[i];
		tmp++;
		i++;
	}
	return (str);
}

static	int		ft_undefined_copy(char *f, int tmp, int i)
{
	int count;

	count = 0;
	while (f[tmp] == 'h' || f[tmp] == 'j' || f[tmp] == 'z' || f[tmp] == 'l'
			|| f[tmp] == ' ' || f[tmp] == '#')
		tmp++;
	while (tmp <= i)
	{
		ft_putchar(f[tmp]);
		count++;
		tmp++;
	}
	return (count);
}

static	int		ft_undefined_percent(char *f, int tmp, int i)
{
	int		count;
	int		tmp2;
	char	*arg;
	int		j;

	tmp2 = tmp;
	j = 0;
	count = 0;
	while (tmp < i)
	{
		if ((f[tmp] < '0' || f[tmp] > '9') && f[tmp] != '%' && f[tmp] != '.' &&
				f[tmp] != '-' && f[tmp] != ' ' && f[tmp])
			return (ft_undefined_copy(f, tmp2, i - 1));
		tmp++;
	}
	arg = (char*)malloc(sizeof(char) * i - tmp2 + 1);
	tmp = tmp2;
	while (tmp < i)
		arg[j++] = f[tmp++];
	ft_precision2(arg);
	count = ft_print_perc('%');
	free(arg);
	return (count);
}

static int		ft_verif_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != 'c' && arg[i] != 'C' && arg[i] != 'u' && arg[i] != 'U' &&
				arg[i] != 'i' && arg[i] != 'd' && arg[i] != 'D' && arg[i] !=
				'x' && arg[i] != 'X' && arg[i] != 's' && arg[i] != 'S' &&
				arg[i] != 'o' && arg[i] != 'O' && arg[i] != 'p' && arg[i] != 'h'
				&& arg[i] != 'j' && arg[i] != 'z' && arg[i] != 'l' && arg[i] !=
				' ' && arg[i] != '#' && arg[i] != '-' && (arg[i] < '0' || arg[i]
					> '9') && arg[i] != '+' && arg[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int				ft_check_arg(char *f, int i, char **arg, int *j)
{
	int tmp;

	tmp = i;
	while (f[i])
	{
		if (f[i] == 'c' || f[i] == 'C' || f[i] == 'd' || f[i] == 'D' || f[i] ==
				'i' || f[i] == 's' || f[i] == 'S' || f[i] == 'p' || f[i] == 'o'
				|| f[i] == 'O' || f[i] == 'u' || f[i] == 'U' || f[i] == 'x' ||
				f[i] == 'X')
		{
			*arg = ft_copy(f, tmp);
			if (ft_verif_arg(*arg) == 0)
				return (-1);
		}
		if (f[i] == '%')
		{
			*j = i - 1;
			if (f[tmp] == '%' && f[i + 1])
				*j = i;
			return (ft_undefined_percent(f, tmp, i));
		}
		i++;
	}
	*j = i - 1;
	return (ft_undefined_copy(f, tmp, i - 1));
}

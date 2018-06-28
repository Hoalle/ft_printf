/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:29:53 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/28 15:14:33 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_undefined_copy_s(char *f, int tmp, int i, int count)
{
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

int				ft_undefined_copy(char *f, int tmp, int i)
{
	int		count;
	int		j;
	int		tmp2;
	char	*arg;

	count = 0;
	j = 0;
	tmp2 = tmp;
	arg = (char*)malloc(sizeof(char) * i - tmp2 + 1);
	while (tmp2 < i)
		arg[j++] = f[tmp2++];
	ft_reset();
	ft_precision2(arg);
	if (g_minfd != 0 || g_p != 0)
	{
		while ((f[tmp] >= '0' && f[tmp] <= '9') || f[tmp] == ' ' || f[tmp] ==
				'-' || f[tmp] == '.')
			tmp++;
		count = ft_prec_undefined(tmp, count, f);
		if (g_noprec == '-')
			tmp++;
	}
	count = ft_undefined_copy_s(f, tmp, i, count);
	free(arg);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:29 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/13 15:31:38 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	ft_precision2_part1(char *arg, int i, int j, char *nb)
{
	while (arg[i - 1] >= '0' && arg[i - 1] <= '9')
		i--;
	if (arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (arg[i - 1] == '0')
	{
		g_zero = '0';
		i++;
	}
	while (arg[i - 1] >= '0' && arg[i - 1] <= '9')
	{
		nb[j] = arg[i - 1];
		i++;
		j++;
	}
	nb[j] = '\0';
	g_p = ft_atoi(nb);
	g_prec = '.';
	j = 0;
	if (arg[i] == '.')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
		nb[j++] = arg[i++];
	nb[j] = '\0';
	g_minfd = ft_atoi(nb);
}

static	void	ft_precision2_part2(char *arg, char *nb, int i, int j)
{
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
		{
			if (arg[i] == '0')
			{
				g_zero = '0';
				i++;
			}
			j = 0;
			if (arg[i] >= '0' && arg[i] <= '9')
			{
				while (arg[i] >= '0' && arg[i] <= '9')
				{
					nb[j] = arg[i];
					i++;
					j++;
				}
				nb[j] = '\0';
				g_minfd = ft_atoi(nb);
			}
		}
		i++;
	}
}

int				ft_precision2(char *arg)
{
	int		i;
	int		j;
	char	*nb;

	i = 0;
	j = 0;
	nb = (char*)malloc(sizeof(char));
	while (arg[i] != '.' && arg[i])
		i++;
	if (arg[i] == '.')
		ft_precision2_part1(arg, i, j, nb);
	i = 0;
	if (((g_minfd == 0 && g_p == 0) || g_minfd == 0) && g_prec != '.')
		ft_precision2_part2(arg, nb, i, j);
	i = 0;
	while (arg[i])
	{
		if (arg[i++] == '-')
			g_noprec = '-';
	}
	free(nb);
	return (0);
}

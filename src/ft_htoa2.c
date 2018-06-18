/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:42:43 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 14:25:19 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		hexa_valuelong(unsigned long int nb, int n)
{
	if (nb <= 9)
		return (48 + nb);
	else if (10 <= nb && nb <= 15)
	{
		nb = nb - 10;
		return (n + nb);
	}
	return (0);
}

char			*ft_long_htoa(unsigned long int nb, int n)
{
	char				*str;
	int					len;
	unsigned long int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 16;
		str[len] = hexa_valuelong(tmp, n);
		nb = nb / 16;
		len--;
	}
	return (str);
}

static int		hexa_value(unsigned int nb, int n)
{
	if (nb <= 9)
		return (48 + nb);
	else if (10 <= nb && nb <= 15)
	{
		nb = nb - 10;
		return (n + nb);
	}
	return (0);
}

char			*ft_char_htoa(unsigned int nb, int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	nb = ft_unsigned_char(nb);
	tmp = nb;
	len = 0;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 16;
		str[len] = hexa_value(tmp, n);
		nb = nb / 16;
		len--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:11:18 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/15 14:30:30 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_utoa(unsigned int nb)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char		*ft_char_utoa(unsigned int nb)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	nb = ft_unsigned_char(nb);
	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char		*ft_longlong_utoa(unsigned long long int nb)
{
	char					*str;
	int						len;
	unsigned long long int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char		*ft_short_utoa(unsigned short int nb)
{
	char				*str;
	int					len;
	unsigned short int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char		*ft_long_utoa(unsigned long int nb)
{
	char				*str;
	int					len;
	unsigned long int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}

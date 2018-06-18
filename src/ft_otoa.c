/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:05 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/15 14:30:50 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_otoa(unsigned int nb)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = nb;
	len = 0;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 8;
		str[len] = 48 + tmp;
		nb = nb / 8;
		len--;
	}
	return (str);
}

char			*ft_char_otoa(unsigned int nb)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	len = 0;
	nb = ft_unsigned_char(nb);
	tmp = nb;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 8;
		str[len] = 48 + tmp;
		nb = nb / 8;
		len--;
	}
	return (str);
}

static	char	*ft_s_llotoa(void)
{
	char *str;

	str = ft_strdup("1777777777777777777777");
	return (str);
}

char			*ft_longlong_otoa(unsigned long long int nb)
{
	char					*str;
	int						len;
	unsigned long long int	tmp;

	len = 0;
	tmp = nb;
	if (nb == ULLONG_MAX)
		return (ft_s_llotoa());
	while (tmp > 7)
	{
		tmp = tmp / 8;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 8;
		str[len--] = 48 + tmp;
		nb = nb / 8;
	}
	return (str);
}

char			*ft_long_otoa(unsigned long int nb)
{
	char				*str;
	int					len;
	unsigned long int	tmp;

	tmp = nb;
	len = 0;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 8;
		str[len] = 48 + tmp;
		nb = nb / 8;
		len--;
	}
	return (str);
}

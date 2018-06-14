/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:19:42 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 11:58:51 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_short_write(char *str, short int n, int len)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	str[len] = '\0';
	len--;
	while (len >= i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char			*ft_short_itoa(short int n)
{
	char		*str;
	int			len;
	short int	temp;

	temp = n;
	len = 0;
	if ((unsigned short int)n == USHRT_MAX)
		return (str = ft_strdup("65535"));
	if (n == -32768)
	{
		str = ft_strdup("-32768");
		return (str);
	}
	if (n < 0)
		len++;
	while (temp > 9 || temp < -9)
	{
		temp = temp / 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 2))))
		return (0);
	len++;
	str = ft_short_write(str, n, len);
	return (str);
}

static char		*ft_longlong_write(char *str, long long int n, int len)
{
	long long int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	str[len] = '\0';
	len--;
	while (len >= i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char			*ft_longlong_itoa(long long int n)
{
	char			*str;
	int				len;
	long long int	temp;

	temp = n;
	len = 0;
	if (n == -9223372036854775807 - 1)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (n < 0)
		len++;
	while (temp > 9 || temp < -9)
	{
		temp = temp / 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 2))))
		return (0);
	len++;
	str = ft_longlong_write(str, n, len);
	return (str);
}

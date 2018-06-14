/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:19:42 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/14 12:00:08 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_write(char *str, int n, int len)
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

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			temp;

	temp = n;
	len = 0;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
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
	str = ft_write(str, n, len);
	return (str);
}

static char		*ft_long_write(char *str, long int n, int len)
{
	long int	i;

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

char			*ft_long_itoa(long int n)
{
	char		*str;
	int			len;
	long int	temp;

	temp = n;
	len = 0;
	if (n == (-9223372036854775807 - 1))
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
	str = ft_long_write(str, n, len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:55:48 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/13 16:35:56 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_letter(va_list ap, char c, char flags, char *arg)
{
	if (c == 'c' || c == 'C')
		return (ft_print_char(ap, c));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_print_nbr(ap, c, flags, arg));
	if (c == 's' || c == 'S')
		return (ft_print_str(ap, c));
	if (c == 'o' || c == 'O')
		return (ft_print_octal(ap, c, arg, flags));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(ap, c, arg, flags));
	if (c == '%')
		return (ft_print_perc(c));
	if (c == 'u' || c == 'U')
		return (ft_print_unsigned(ap, c, arg, flags));
	if (c == 'p')
		return (ft_print_p(ap, arg));
	return (0);
}

static	int		ft_s_pr(va_list ap, char *format, int count, int *i)
{
	char	flags;
	char	*arg;
	int		ret;
	int		j;

	arg = NULL;
	ret = ft_check_arg((char*)format, (*i) + 1, &arg, &j);
	if (ret == -1)
	{
		if (ft_strlen(arg) == 1)
			count = count + ft_letter(ap, format[(*i) + 1], '0', arg);
		if (ft_strlen(arg) != 1)
		{
			ft_reset();
			ft_precision(ap, arg);
			flags = ft_check_flags(arg);
			count += ft_letter(ap, format[(*i) + ft_strlen(arg)], flags, arg);
		}
		(*i) = (*i) + ft_strlen(arg);
		free(arg);
		return (count);
	}
	(*i) = j;
	free(arg);
	return (count + ret);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	int			count;

	i = 0;
	va_start(ap, format);
	count = 0;
	while (format[i])
	{
		ft_reset();
		if (format[i] == '%')
			count = ft_s_pr(ap, (char*)format, count, &i);
		else if (format[i] != '%')
		{
			count++;
			write(1, &format[i], 1);
		}
		i++;
	}
	i++;
	return (count);
}

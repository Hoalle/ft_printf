/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:25:41 by cperrard          #+#    #+#             */
/*   Updated: 2018/06/18 17:33:47 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>

int g_p;
int g_minfd;
char g_prec;
char g_zero;
char g_noprec;

int		ft_printf(const char *format, ...);
char	ft_check_flags(char *arg);
int		ft_check_arg(char *f, int i, char **arg, int *j);
int		ft_precision(va_list ap, char *arg);
int		ft_precision2(char *arg);
void	ft_no_prec(char *nbr, int nbflags, int c);
int		ft_len_ret_nbr(int nbflags, int lenbr);
int		ft_check_flags_nbr(char *arg);
void	ft_reset();
char	ft_l_nbr(char *arg, char car, char flags);
int		ft_signed_char(int n);
int		ft_unsigned_char(unsigned int n);
int		main(void);

int		ft_print_char(va_list ap, char car);
int		ft_print_str(va_list ap, char car);
int		ft_print_nbr(va_list ap, char car, char flags, char *arg);
int		ft_print_octal(va_list ap, char car, char *arg, char flags2);
int		ft_print_hexa(va_list ap, char car, char *arg, char flags2);
int		ft_print_unsigned(va_list ap, char car, char *arg, char flags2);
int		ft_print_p(va_list ap, char *arg);
int		ft_print_perc(char c);
int		ft_s_nolen(void);
int		ft_len_ret2(void);
int		ft_write_flags_octal(char *arg);
int		ft_ret_s1();

char	*ft_itoa(int n);
int		ft_atoi(char *nb);
char	*ft_long_itoa(long int n);
char	*ft_longlong_itoa(long long int n);
char	*ft_short_itoa(short int n);
char	*ft_char_itoa(int n);
char	*ft_otoa(unsigned int nb);
char	*ft_longlong_otoa(unsigned long long int nb);
char	*ft_long_otoa(unsigned long int nb);
char	*ft_char_otoa(unsigned int nb);
char	*ft_htoa(unsigned int nb, int n);
char	*ft_char_htoa(unsigned int nb, int n);
char	*ft_long_htoa(unsigned long int nb, int n);
char	*ft_longlong_htoa(unsigned long long int nb, int n);
char	*ft_utoa(unsigned int nb);
char	*ft_char_utoa(unsigned int nb);
char	*ft_short_utoa(unsigned short int nb);
char	*ft_long_utoa(unsigned long int nb);
char	*ft_longlong_utoa(unsigned long long int llgc);
int		ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putwstr(wchar_t *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		ft_strcmp(char *s1, char *s2);

int		ft_minfd_nbr(int len, int nbflags, char *nbr);
int		ft_prec_nbr(int flags, int nbflags, char *nbr, int len);
int		ft_write_flags_nbr(int flags, char *nbr);
int		ft_prec_min_oxu(int flags, int len, char *arg, char car);
int		ft_prec_min_str(int len, char *str);

#endif

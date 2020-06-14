/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:59:59 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 08:13:45 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			wid;
	int			dot;
	int			prec;
	int			printed;
	int			type;
	int			var_printed;
	int			var_len;
	char		*hex;
}				t_info;

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int				ft_printf(const char *fmt, ...);
int				parsing(const char *fmt, va_list arg, t_info *info);
void			init_info(t_info *info);
void			read_flag_wid(t_info *info, const char **fmt, va_list ap);
void			read_prec_spec(t_info *info, const char **fmt, va_list ap);
void			printing(va_list ap, t_info *info);
size_t			usigned_len(unsigned long long n);
size_t			signed_len(long long n);
size_t			ft_strlen(char *s);
int				hex_len(unsigned int n);
void			ft_putchar_n(char c, int n, t_info *info);
void			ft_putstr_n(char *s, int n, t_info *info);
void			ft_putchar(char c, t_info *info);
void			ft_putstr(char *s, t_info *info);
void			ft_putnbr(long long n, t_info *info);
char			*ft_strdup(char *src);
void			case_d(t_info *info, int n);
void			case_d_dot(t_info *info, int n);
void			case_u(t_info *info, unsigned int n);
void			case_x(t_info *info, size_t n);
void			case_x_dot(t_info *info);
char			*dec_to_upperhex(size_t n);
char			*dec_to_lowerhex(size_t n);
void			case_s(t_info *info, char *s);
void			case_s_dot(t_info *info, char *s);
void			case_c(t_info *info, int c);
void			case_c_dot(t_info *info, char c);
void			case_p(t_info *info, size_t s);
void			case_p_dot(t_info *info);

#endif

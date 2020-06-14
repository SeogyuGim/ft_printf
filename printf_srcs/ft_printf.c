/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:57:42 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 08:11:05 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	init_info(t_info *info)
{
	info->wid = 0;
	info->prec = 0;
	info->dot = 0;
	info->minus = 0;
	info->zero = 0;
	info->printed = 0;
	info->type = 0;
	info->var_len = 0;
	info->hex = 0;
}

int		parsing(const char *fmt, va_list ap, t_info *info)
{
	int			ret;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			read_flag_wid(info, &fmt, ap);
			read_prec_spec(info, &fmt, ap);
			printing(ap, info);
			init_info(info);
		}
		while (*fmt != '%' && *fmt)
		{
			write(1, fmt++, 1);
			info->var_printed++;
		}
	}
	ret = info->var_printed;
	return (ret);
}

void	printing(va_list ap, t_info *info)
{
	if (info->type == 'd' || info->type == 'i')
		case_d(info, va_arg(ap, int));
	else if (info->type == 'u')
		case_u(info, va_arg(ap, int));
	else if (info->type == 'x' || info->type == 'X')
		case_x(info, va_arg(ap, unsigned int));
	else if (info->type == 's')
		case_s(info, va_arg(ap, char *));
	else if (info->type == 'c')
		case_c(info, va_arg(ap, int));
	else if (info->type == '%')
		case_c(info, '%');
	else if (info->type == 'p')
		case_p(info, va_arg(ap, size_t));
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	va_list		cp;
	int			printed;
	t_info		*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	init_info(info);
	info->var_printed = 0;
	va_start(ap, fmt);
	va_copy(cp, ap);
	printed = parsing(fmt, ap, info);
	free(info);
	init_info(info);
	info->var_printed = 0;
	va_end(cp);
	return (printed);
}

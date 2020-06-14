/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:58:27 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 09:01:51 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	read_flag_wid(t_info *info, const char **fmt, va_list ap)
{
	while (**fmt == ' ' || **fmt == '+' || **fmt == '-'
			|| **fmt == '0' || **fmt == '#')
	{
		if (**fmt == '-')
			info->minus++;
		if (**fmt == '0')
			info->zero++;
		(*fmt)++;
	}
	if (info->minus && info->zero)
		info->zero = 0;
	if (**fmt == '*')
	{
		info->wid = va_arg(ap, int);
		if (info->wid < 0)
		{
			info->wid *= -1;
			info->minus++;
		}
		(*fmt)++;
	}
	while (**fmt >= '0' && **fmt <= '9')
		info->wid = info->wid * 10 + *(*fmt)++ - '0';
}

void	read_prec_spec(t_info *info, const char **fmt, va_list ap)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		info->dot++;
		if (**fmt == '*')
		{
			info->prec = va_arg(ap, int);
			if (info->prec < 0)
			{
				info->prec = 0;
				info->dot = 0;
			}
			(*fmt)++;
		}
		while (**fmt >= '0' && **fmt <= '9')
			info->prec = info->prec * 10 + *(*fmt)++ - '0';
	}
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u' || **fmt == 'x'
			|| **fmt == 'X' || **fmt == 'p' || **fmt == 's' || **fmt == 'c'
			|| **fmt == '%')
		info->type = *(*fmt)++;
	if (info->minus && info->zero)
		info->zero = 0;
	if (info->type == 'p')
		info->wid -= 2;
}

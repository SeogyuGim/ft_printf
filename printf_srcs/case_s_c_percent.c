/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s_c_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 07:33:17 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 08:48:37 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	case_s_dot(t_info *info, char *s)
{
	if (info->minus)
	{
		ft_putstr_n(s, info->prec, info);
		ft_putchar_n(' ', info->wid - info->prec, info);
		if (info->prec >= info->var_len && info->wid >= info->prec)
			ft_putchar_n(' ', info->prec - info->var_len, info);
		else if (info->prec > info->var_len
				&& info->wid < info->prec && info->wid)
			ft_putchar_n(' ', info->prec - info->wid - info->var_len, info);
		return ;
	}
	ft_putchar_n(' ', info->wid - info->prec, info);
	if (info->prec >= info->var_len && info->wid >= info->prec)
		ft_putchar_n(' ', info->prec - info->var_len, info);
	else if (info->prec > info->var_len && info->wid < info->prec && info->wid)
		ft_putchar_n(' ', info->prec - info->wid - info->var_len, info);
	ft_putstr_n(s, info->prec, info);
}

void	case_s(t_info *info, char *s)
{
	if (s == NULL)
		s = "(null)";
	info->var_len = ft_strlen(s);
	if (info->dot)
		case_s_dot(info, s);
	else if (info->minus)
	{
		ft_putstr(s, info);
		ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		ft_putchar_n('0', info->wid - info->var_len, info);
		ft_putstr(s, info);
	}
	else
	{
		ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putstr(s, info);
	}
}

void	case_c_dot(t_info *info, char c)
{
	if (info->minus)
	{
		ft_putchar(c, info);
		ft_putchar_n(' ', info->wid - info->prec, info);
		if (info->prec >= info->var_len && info->wid >= info->prec)
			ft_putchar_n(' ', info->prec - info->var_len, info);
		else if (info->prec > info->var_len
				&& info->wid < info->prec && info->wid)
			ft_putchar_n(' ', info->prec - info->wid - info->var_len, info);
		return ;
	}
	ft_putchar_n(' ', info->wid - info->prec, info);
	if (info->prec >= info->var_len && info->wid >= info->prec)
		ft_putchar_n(' ', info->prec - info->var_len, info);
	else if (info->prec > info->var_len && info->wid < info->prec && info->wid)
		ft_putchar_n(' ', info->prec - info->wid - info->var_len, info);
	ft_putchar(c, info);
}

void	case_c(t_info *info, int c)
{
	info->var_len = 1;
	if (info->dot)
		case_c_dot(info, c);
	else if (info->minus)
	{
		ft_putchar(c, info);
		ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		ft_putchar_n('0', info->wid - info->var_len, info);
		ft_putchar(c, info);
	}
	else
	{
		ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putchar(c, info);
	}
}

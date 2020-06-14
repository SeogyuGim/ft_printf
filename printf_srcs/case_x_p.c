/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 07:48:33 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 09:01:25 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	case_x_dot(t_info *info)
{
	if (info->hex[0] == '0')
	{
		free(info->hex);
		info->hex = ft_strdup("");
		info->var_len = 0;
	}
	if (info->minus)
	{
		info->hex[0] != 0 ? ft_putchar_n('0', info->prec - info->var_len, info)
						: ft_putchar_n('0', info->prec, info);
		if (info->hex[0] != 0)
			ft_putstr(info->hex, info);
		if (info->prec > info->var_len)
			ft_putchar_n(' ', info->wid - info->prec, info);
		else
			ft_putchar_n(' ', info->wid - info->var_len, info);
		return ;
	}
	if (info->var_len > info->prec)
		ft_putchar_n(' ', info->wid - info->var_len, info);
	else
		ft_putchar_n(' ', info->wid - info->prec, info);
	info->hex[0] != 0 ? ft_putchar_n('0', info->prec - info->var_len, info)
						: ft_putchar_n('0', info->prec, info);
	ft_putstr(info->hex, info);
}

void	case_x(t_info *info, size_t n)
{
	if (n < 0 || n > UINT32_MAX)
		return ;
	info->hex = info->type == 'x' ? dec_to_lowerhex(n) : dec_to_upperhex(n);
	info->var_len = ft_strlen(info->hex);
	if (info->dot)
		case_x_dot(info);
	else if (info->minus)
	{
		ft_putstr(info->hex, info);
		ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		ft_putchar_n('0', info->wid - info->var_len, info);
		ft_putstr(info->hex, info);
	}
	else
	{
		ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putstr(info->hex, info);
	}
	free(info->hex);
}

void	case_p_dot(t_info *info)
{
	if (info->minus)
	{
		ft_putstr("0x", info);
		ft_putchar_n('0', info->prec - info->var_len, info);
		ft_putstr(info->hex, info);
		if (info->prec > info->var_len)
			ft_putchar_n(' ', info->wid - info->prec, info);
		else
			ft_putchar_n(' ', info->wid - info->var_len, info);
		return ;
	}
	if (info->var_len > info->prec)
		ft_putchar_n(' ', info->wid - info->var_len, info);
	else
		ft_putchar_n(' ', info->wid - info->prec, info);
	ft_putstr("0x", info);
	info->hex[0] != 0 ? ft_putchar_n('0', info->prec - info->var_len, info)
						: ft_putchar_n('0', info->prec, info);
	if (info->hex[0] != 0)
		ft_putstr(info->hex, info);
}

void	case_p(t_info *info, size_t s)
{
	if (info->dot && !info->prec && s == 0)
		info->hex = "";
	else
		info->hex = s != 0 ? dec_to_lowerhex(s) : "0";
	info->var_len = ft_strlen(info->hex);
	if (info->dot)
		case_p_dot(info);
	else if (info->minus)
	{
		ft_putstr("0x", info);
		ft_putstr(info->hex, info);
		ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		ft_putstr("0x", info);
		ft_putchar_n('0', info->wid - info->var_len, info);
		ft_putstr(info->hex, info);
	}
	else
	{
		ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putstr("0x", info);
		ft_putstr(info->hex, info);
	}
}

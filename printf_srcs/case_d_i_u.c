/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d_i_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:57:49 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 08:57:06 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	case_d_dot(t_info *info, int n)
{
	n == 0 ? info->var_len = 0 : 0;
	if (info->minus)
	{
		n < 0 ? ft_putchar('-', info) : 0;
		ft_putchar_n('0', info->prec - info->var_len, info);
		if (n != 0)
			n < 0 ? ft_putnbr((long long)n * -1, info) : ft_putnbr(n, info);
		if (info->prec > info->var_len)
			n < 0 ? ft_putchar_n(' ', info->wid - info->prec - 1, info) :
					ft_putchar_n(' ', info->wid - info->prec, info);
		else
			n < 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
					ft_putchar_n(' ', info->wid - info->var_len, info);
		return ;
	}
	if (info->var_len > info->prec)
		n <= 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
				ft_putchar_n(' ', info->wid - info->var_len, info);
	else
		n < 0 ? ft_putchar_n(' ', info->wid - info->prec - 1, info) :
				ft_putchar_n(' ', info->wid - info->prec, info);
	n < 0 ? ft_putchar('-', info) : 0;
	ft_putchar_n('0', info->prec - info->var_len, info);
	if (n != 0)
		n < 0 ? ft_putnbr((long long)n * -1, info) : ft_putnbr(n, info);
}

void	case_d(t_info *info, int n)
{
	if (n < INT_MIN || n > INT_MAX)
		return ;
	info->var_len = signed_len(n);
	if (info->dot)
		case_d_dot(info, n);
	else if (info->minus)
	{
		ft_putnbr(n, info);
		n <= 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
				ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		n < 0 ? ft_putchar('-', info) : 0;
		n <= 0 ? ft_putchar_n('0', info->wid - info->var_len - 1, info) :
				ft_putchar_n('0', info->wid - info->var_len, info);
		n < 0 ? ft_putnbr((long long)n * -1, info) : ft_putnbr(n, info);
	}
	else
	{
		n <= 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
				ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putnbr(n, info);
	}
}

void	case_u(t_info *info, unsigned int n)
{
	if (n < 0 || n > UINT32_MAX)
		return ;
	info->var_len = signed_len(n);
	if (info->dot)
		case_d_dot(info, n);
	else if (info->minus)
	{
		ft_putnbr(n, info);
		n <= 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
				ft_putchar_n(' ', info->wid - info->var_len, info);
	}
	else if (info->zero)
	{
		n < 0 ? ft_putchar('-', info) : 0;
		n <= 0 ? ft_putchar_n('0', info->wid - info->var_len - 1, info) :
				ft_putchar_n('0', info->wid - info->var_len, info);
		n < 0 ? ft_putnbr((long long)n * -1, info) : ft_putnbr(n, info);
	}
	else
	{
		n <= 0 ? ft_putchar_n(' ', info->wid - info->var_len - 1, info) :
				ft_putchar_n(' ', info->wid - info->var_len, info);
		ft_putnbr(n, info);
	}
}

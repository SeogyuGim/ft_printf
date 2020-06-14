/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:58:23 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 09:08:06 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	ft_putchar_n(char c, int n, t_info *info)
{
	if (n > 0)
	{
		info->var_printed += n;
		while (n--)
			write(1, &c, 1);
	}
}

void	ft_putstr_n(char *s, int n, t_info *info)
{
	if (n > 0)
	{
		while (n-- && *s)
		{
			write(1, s++, 1);
			info->var_printed++;
		}
	}
}

void	ft_putchar(char c, t_info *info)
{
	if (c)
	{
		info->var_printed += 1;
		write(1, &c, 1);
	}
	else if (c == '\0')
	{
		info->var_printed += 1;
		write(1, &c, 1);
	}
}

void	ft_putstr(char *s, t_info *info)
{
	if (s)
	{
		while (*s)
		{
			write(1, s++, 1);
			info->var_printed++;
		}
	}
}

void	ft_putnbr(long long n, t_info *info)
{
	if (n < 0)
	{
		ft_putchar('-', info);
		ft_putnbr(n * -1, info);
	}
	else if (n < 10)
		ft_putchar(n + '0', info);
	else
	{
		ft_putnbr(n / 10, info);
		ft_putchar(n % 10 + '0', info);
	}
}

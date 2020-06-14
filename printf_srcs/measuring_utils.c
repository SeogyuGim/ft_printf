/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measuring_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:58:14 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 03:31:05 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

size_t	usigned_len(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		hex_len(unsigned int n)
{
	int		len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	signed_len(long long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

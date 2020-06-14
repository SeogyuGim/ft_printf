/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:58:03 by seogkim           #+#    #+#             */
/*   Updated: 2020/04/22 08:14:00 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

char	*dec_to_upperhex(size_t n)
{
	char	*ret;
	char	c;
	size_t	i;
	size_t	idx;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(ret = (char*)malloc(sizeof(char) * hex_len(n) + 1)))
		return (NULL);
	i = 0;
	while (n)
	{
		ret[i++] = UPPER_HEX[n % 16];
		n /= 16;
	}
	ret[i] = '\0';
	idx = -1;
	while (--i > ++idx && ret[i])
	{
		c = ret[idx];
		ret[idx] = ret[i];
		ret[i] = c;
	}
	return (ret);
}

char	*dec_to_lowerhex(size_t n)
{
	char	*ret;
	char	c;
	size_t	i;
	size_t	idx;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(ret = (char*)malloc(sizeof(char) * hex_len(n) + 1)))
		return (NULL);
	i = 0;
	while (n)
	{
		ret[i++] = LOWER_HEX[n % 16];
		n /= 16;
	}
	ret[i] = '\0';
	idx = -1;
	while (--i > ++idx && ret[i])
	{
		c = ret[idx];
		ret[idx] = ret[i];
		ret[i] = c;
	}
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char*)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

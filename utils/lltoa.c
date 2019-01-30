/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:04:12 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 10:21:29 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_intlen(long long n)
{
	size_t		ret;
	long long	num;

	ret = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		ret++;
	}
	while (num > 0)
	{
		ret++;
		num = num / 10;
	}
	return (ret);
}

char			*ft_lltoa(long long n)
{
	long		len;
	char		*ret;
	long long	num;

	len = ft_intlen(n);
	CH_NULL(ret = (char*)malloc(sizeof(char) * (len + 1)));
	if (n == MIN(n))
		return (min_integer(sizeof(n)));
	ret[len--] = '\0';
	num = n;
	if (n < 0)
	{
		ret[0] = '-';
		num *= -1;
		len--;
	}
	while (len >= 0)
	{
		ret[(n < 0) ? (len + 1) : len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (ret);
}

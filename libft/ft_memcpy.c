/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:02:37 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/17 18:58:35 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*p1;
	const unsigned char	*p2 = src;

	count = 0;
	p1 = dst;
	while (count < n)
	{
		p1[count] = p2[count];
		count++;
	}
	return (dst);
}

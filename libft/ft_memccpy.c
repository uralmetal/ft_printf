/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:19:35 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/12 13:09:41 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				count;
	unsigned char		*p_dst;
	const unsigned char	*p_src = src;

	count = 0;
	p_dst = dst;
	while ((count < n) && (p_src[count] != (unsigned char)c))
	{
		p_dst[count] = p_src[count];
		count++;
	}
	if (count != n)
	{
		p_dst[count] = p_src[count];
		return ((void *)(p_dst + count + 1));
	}
	else
		return (NULL);
}

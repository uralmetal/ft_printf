/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:22:41 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/12 18:28:01 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				count;
	const unsigned char	*p = s;

	count = 0;
	while ((count < n) && (p[count] != (unsigned char)c))
		count++;
	if (count != n)
		return ((void *)(p + count));
	else
		return (NULL);
}

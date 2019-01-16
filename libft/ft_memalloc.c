/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:00:15 by rwalder-          #+#    #+#             */
/*   Updated: 2018/11/26 16:33:05 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	count;

	p = (char*)malloc(size);
	if (p == NULL)
		return (NULL);
	count = 0;
	while (count < size)
		p[count++] = 0;
	return ((void*)(p));
}

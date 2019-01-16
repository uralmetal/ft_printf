/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:15:01 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/13 13:31:20 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	count;

	p = (char*)malloc(size + 1);
	if (p == NULL)
		return (NULL);
	count = 0;
	while (count < size + 1)
		p[count++] = 0;
	return (p);
}

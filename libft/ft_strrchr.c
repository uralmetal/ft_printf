/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:40:42 by rwalder-          #+#    #+#             */
/*   Updated: 2018/11/27 20:30:20 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;
	int end;

	count = ft_strlen((char*)s);
	end = 1;
	while (count >= 0)
	{
		if (s[count] == (unsigned char)c)
		{
			end = 0;
			break ;
		}
		count--;
	}
	if (end == 0)
		return ((char*)(s + count));
	else
		return (NULL);
}

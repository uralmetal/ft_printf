/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:29:01 by rwalder-          #+#    #+#             */
/*   Updated: 2018/12/12 13:01:48 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;
	int end;

	count = 0;
	end = 0;
	while (s[count] != c)
	{
		if (s[count] == '\0')
		{
			end = 1;
			break ;
		}
		count++;
	}
	if (end == 0)
		return ((char*)(s + count));
	else
		return (NULL);
}

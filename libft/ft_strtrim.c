/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:30:20 by rwalder-          #+#    #+#             */
/*   Updated: 2018/11/28 15:16:05 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin_str(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	end_str(const char *s)
{
	int len;

	len = ft_strlen((char*)s) - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			&& len >= 0)
		len--;
	return (len);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		len;
	char	*ret;
	char	*begin;

	if (s == NULL)
		return (NULL);
	i = begin_str(s);
	len = end_str(s);
	if ((len - i + 1) >= 0)
	{
		if (!(ret = (char*)malloc(sizeof(char) * (len - i + 2))))
			return (NULL);
		begin = ret;
		while (i <= len)
			*(ret++) = s[i++];
		*ret = '\0';
	}
	else
	{
		begin = (char*)malloc(sizeof(char));
		if (begin)
			begin[0] = '\0';
	}
	return (begin);
}

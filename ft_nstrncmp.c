/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:23:21 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/03 16:51:49 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char *size = "hzjlL";
static const char *type = "cspi%douxXfegGFSCaAnDOUbkr";

char *check_type(const char *fmt, char *ret, size_t *i)
{
	int j;
	int k;
	char spec[20];

	k = -1;
	j = 0;
	ft_bzero(spec, 20);
	while (size[j])
	{
		if (fmt[*i] == size[j])
		{
			while (fmt[*i] == size[j])
			{
				spec[++k] = size[j];
				*i += 1;
			}
			j = -1;
		}
		check_flags(mod, fmt, i);
		j++;
	}
	j = -1;
	while (type[++j])
		if (fmt[*i] == type[j])
		{
			*i += 1;
			break;
		}
	if (type[j] == '\0')
		return (NULL);
	if (type[j] != '\0' && *spec != '\0')
		check_multiflag(ret, spec, (int) ft_strlen(spec), type[j]);
	if (*ret != '\0')
		ret[ft_strlen(ret)] = type[j];
	else
	{
		if (type[j] == '\0')
			return (NULL);
		*ret = type[j];
		return (NULL);
	}
	return (NULL);
}
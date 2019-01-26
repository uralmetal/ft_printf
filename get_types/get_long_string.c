/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:40:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 18:40:02 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int ft_wstrlen(wchar_t *arg)
{
	int i;

	i = 0;
	while (i < arg[i])
		i++;
	return (i);
}

char *get_long_string(const void *arg)
{
	const wchar_t *s = arg;
	const char *src = arg;
	char *ret;
	int len;

	len = ft_wstrlen(arg);
	ret = ft_strnew(len * sizeof(wchar_t));
	ft_memcpy(ret, src, len * sizeof(wchar_t));
	return (ret);
}
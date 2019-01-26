/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:38:16 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 18:39:05 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *get_long_char(const void *arg)
{
	char *ret;
	int i;

	ret = ft_strnew(sizeof(wchar_t));
	i = 0;
	while (i < sizeof(wchar_t))
		ret[i++] = (*(char*)(arg + i));
	return (ret);
}

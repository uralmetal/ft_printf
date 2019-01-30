/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 08:33:49 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/30 10:21:29 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_percent(const void * arg)
{
	char *ret;

	ret = (char*)arg;
	ret = ft_strnew(1);
	ret[0] = '%';
	return (ret);
}

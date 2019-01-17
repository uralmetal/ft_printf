/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:18:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/17 17:40:24 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const get_output g_get_function_array[] = {
	&get_char,
	&get_string,
	&get_pointer
};

static const char g_modificators_array[][4] = {
	"c",
	"s",
	"p"
};

get_output	get_function(t_print mod)
{
	int			index;
	int 		size;

	size = sizeof(g_modificators_array) / sizeof(g_modificators_array[0]);
	index = 0;
	while (index < size)
	{
		if (ft_strcmp(g_modificators_array[index], mod.type) == 0)
			return (g_get_function_array[index]);
		index++;
	}
	return (NULL);
}
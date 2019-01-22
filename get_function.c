/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:18:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/20 18:57:41 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const get_output g_get_function_array[] = {
	&get_char,
	&get_string,
	&get_pointer,
	&get_int
};

get_output	get_function(t_print *mod)
{
	int 		size;

	size = sizeof(g_get_function_array) / sizeof(g_get_function_array[0]);
	if (size < mod->type)
		return (NULL);
	return (g_get_function_array[mod->type]);
}
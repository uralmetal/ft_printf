/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:18:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/23 12:01:15 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const get_output g_get_function_array[] = {
	&get_char,
	&get_string,
	&get_pointer,
	&get_int,
	&get_percent,
	&get_int,
	&get_unsigned_int_oct,
	&get_unsigned_int,
	&get_unsigned_int_hex,
	&get_unsigned_int_hex_upper,
	&get_float,
	&get_long_double,
	&get_char,
	&get_char,
	&get_unsigned_char_oct,
	&get_unsigned_char,
	&get_unsigned_char_hex,
	&get_unsigned_char_hex_upper,
	&get_short,
	&get_short,
	&get_unsigned_short_oct,
	&get_unsigned_char,
	&get_unsigned_short_hex,
	&get_unsigned_short_hex_upper,
	&get_double,
	&get_long,
	&get_long,
	&get_unsigned_long_oct,
	&get_unsigned_long,
	&get_unsigned_long_hex,
	&get_unsigned_long_hex_upper,
	&get_long_long,
	&get_long_long,
	&get_unsigned_long_long_oct,
	&get_unsigned_long_long,
	&get_unsigned_long_long_hex,
	&get_unsigned_long_long_hex_upper
};

get_output	get_function(t_print *mod)
{
	int 		size;

	size = sizeof(g_get_function_array) / sizeof(g_get_function_array[0]);
	if (size < mod->type)
		return (NULL);
	return (g_get_function_array[mod->type]);
}
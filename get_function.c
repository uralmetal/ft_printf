/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:18:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/26 16:36:04 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const get_output g_get_function_array[] = {
	/*0*/&get_char,
	/*1*/&get_string,
	/*2*/&get_pointer,
	/*3*/&get_int,
	/*4*/&get_percent,
	/*5*/NULL, //==   3
	/*6*/&get_unsigned_int_oct,
	/*7*/&get_unsigned_int,
	/*8*/&get_unsigned_int_hex,
	/*9*/&get_unsigned_int_hex_upper,
	/*10*/&get_double,
	/*11*/&get_long_double,
	/*12*/&get_signed_char,
	/*13*/NULL, //==   12
	/*14*/&get_unsigned_char_oct,
	/*15*/&get_unsigned_char,
	/*16*/&get_unsigned_char_hex,
	/*17*/&get_unsigned_char_hex_upper,
	/*18*/&get_short,
	/*19*/NULL, //==   18
	/*20*/&get_unsigned_short_oct,
	/*21*/&get_unsigned_char,
	/*22*/&get_unsigned_short_hex,
	/*23*/&get_unsigned_short_hex_upper,
	/*24*/&get_double,
	/*25*/&get_long,
	/*26*/NULL,//==   25
	/*27*/&get_unsigned_long_oct,
	/*28*/&get_unsigned_long,
	/*29*/&get_unsigned_long_hex,
	/*30*/&get_unsigned_long_hex_upper,
	/*31*/&get_long_long,
	/*32*/NULL,//==   31
	/*33*/&get_unsigned_long_long_oct,
	/*34*/&get_unsigned_long_long,
	/*35*/&get_unsigned_long_long_hex,
	/*36*/&get_unsigned_long_long_hex_upper,
	/*37*/&get_double_exp,
	/*38*/&get_double_g,
	/*39*/NULL,//==   37
	/*40*/NULL,//==   38
	/*41*/&get_long_double_exp,
	/*42*/&get_long_double_g,
	/*43*/&get_double_g_upper,
	/*44*/NULL,//==   43
	/*45*/&get_long_double_g_upper,
	/*46*/&get_double_upper,
	/*47*/NULL,//==   46
	/*48*/&get_long_double_upper,
	/*49*/&get_double_exp_upper,
	/*50*/NULL,//==   49
	/*51*/&get_long_double_exp_upper,
	/*52*/&get_long_string,
	/*53*/NULL,//==   52
	/*54*/&get_long_char,
	/*55*/NULL//==   54
//	/*56*/&get_,
//	/*57*/&get_,
	};

get_output	get_function(t_print *mod)
{
	int 		size;

	size = sizeof(g_get_function_array) / sizeof(g_get_function_array[0]);
	if (size < mod->type)
		return (NULL);
	return (g_get_function_array[mod->type]);
}
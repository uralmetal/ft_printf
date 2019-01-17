/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:01:34 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/17 11:06:26 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print(t_print modificators, const void *arg)
{
	get_output function_get;
	char *output;

	if (modificators.type[0] == 'c')
		function_get = &get_char;
	output = function_get(arg);
	ft_putstr(output);
	ft_strdel(&output);
}
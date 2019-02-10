/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:39:26 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/07 19:27:16 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*choose_arg_prec_0(const void **arg, t_get_output function_get,
						double var_d, long double var_dd)
{
	char *output;

	output = NULL;
	if (var_d != 0.0 || var_d == (-0.0))
		output = function_get(var_d, 6);
	else if (var_dd != 0 || (var_dd == -0, var_d == 0 && *arg == 0 &&
	g_mod->type != 1 && g_mod->type != 52))
		output = function_get(var_dd, 6);
	else
		output = function_get(arg, -1);
	return (output);
}

char	*choose_arg_prec(const void **arg, t_get_output function_get,
						double var_d, long double var_dd)
{
	char *output;

	output = NULL;
	if (var_d != 0.0 || var_d == (-0.0))
		output = function_get(var_d, g_mod->precision);
	else if (var_dd != 0 || (var_dd == -0, var_d == 0 && *arg == 0 &&
			g_mod->type != 1 && g_mod->type != 52))
		output = function_get(var_dd, g_mod->precision);
	else
		output = function_get(arg, g_mod->precision);
	return (output);
}

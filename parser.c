/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:06:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/01 15:11:31 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parser(va_list ap, va_list start, size_t i)
{
	void *p;
	int *spec_n;
	double var_d;
	long double var_dd;


	p = NULL;
	var_d = 0;
	var_dd = 0;

	if (mod->error == 1)
		return (1);
	if (mod->type == 4)
		return (print(mod, NULL, 0, 0));
	va_arg_width(start, ap);
	va_arg_precision(start, ap);
	if (mod->type == 10 || mod->type == 24 || mod->type == 37 ||
		mod->type == 38 || mod->type == 43 || mod->type == 46 ||
		mod->type == 49)
	{
		if (mod->num_arg == 0)
			var_d = va_arg(ap, double);
		else
			va_arg_num_d(start, mod->num_arg, &var_d);
	}
	else
	{
		if (mod->type == 11 || mod->type == 41 || mod->type == 42 ||
				mod->type == 48 || mod->type == 51)
		{
			if (mod->num_arg == 0)
				var_dd = va_arg(ap, long double);
			else
				va_arg_num_dd(start, mod->num_arg, &var_dd);
		}
		else
		{
			if (mod->num_arg == 0)
				p = va_arg(ap, void *);
			else
				va_arg_num(start, mod->num_arg, &p);
		}
	}
	if (mod->type == 62)
	{
		spec_n = p;
		*spec_n = g_output_symbols;
		return (1);
	}
	if (print(mod, &p, var_d, var_dd) == 0)
		return (0);
	return (1);
}


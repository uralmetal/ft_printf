/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:33:13 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/03 13:10:47 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void va_arg_num_int(va_list start, int num_arg, int *value)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		(void)va_arg(start_start, int);
	*value = va_arg(start_start, int);
	va_end(start_start);
}

void va_arg_num(va_list start, int num_arg, void **p)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		(void)va_arg(start_start, void *);
	*p = va_arg(start_start, void *);
	va_end(start_start);
}

void va_arg_num_d(va_list start, int num_arg, double *var_d)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		(void)va_arg(start_start, double);
	*var_d = va_arg(start_start, double);
	va_end(start_start);
}

void va_arg_num_dd(va_list start, int num_arg, long double *var_dd)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		(void)va_arg(start_start, long double);
	*var_dd = va_arg(start_start, long double);
	va_end(start_start);
}

void va_arg_precision(va_list start, va_list ap)
{
	t_print *cursor;
	va_list dest;
	int j;

	if (mod->prec_num_arg != -1  && mod->precision == -1)
	{
		mod->precision = va_arg(ap, int);
		return ;
	}
	j = 0;
	va_copy(dest, start);
	cursor = start_list;
	if (mod->prec_num_arg != -1)
	{
		if (find_d_dd() == 0)
			va_arg_num_int(start, mod->prec_num_arg, &(mod)->precision);
		else
			while (++j != mod->width_num_arg)
			{
				IF_D_DD(cursor->type)
					(void)va_arg(dest, long double);
				else
					(void) va_arg(dest, void *);
				cursor = cursor->next;
			}
	}
	if (mod->precision < 0 && mod->precision != -1)
		mod->precision = 0;
	va_end(dest);
}

void	va_arg_width(va_list start, va_list ap)
{
	t_print *cursor;
	va_list dest;
	int j;
	int buf;

	j = 0;
	va_copy(dest, start);
	cursor = start_list;
	buf = mod->width;
	if (mod->width_num_arg == 0)
		mod->width = va_arg(ap, int);
	if(mod->width_num_arg != 0 && mod->width_num_arg != -1)
	{
		if (find_d_dd() == 0)
			va_arg_num_int(start, mod->width_num_arg, &(mod)->width);
		else
			while (++j != mod->width_num_arg)
			{
				IF_D_DD(cursor->type) (void) va_arg(dest, long double);
				else
					(void) va_arg(dest, void *);
				cursor = cursor->next;
			}
	}
	if (mod->width < 0)
	{
		while (mod->flag[j] != '0' && mod->flag[j] && mod->flag[j] != '-')
			j++;
		mod->flag[j] = '-';
		mod->width <= -2147483648 ? (mod->width = 0) : (mod->width *= -1);
	}
	if (buf > 0)
		mod->width = buf;
	va_end(dest);
}
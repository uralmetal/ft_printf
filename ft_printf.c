/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/29 18:59:59 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	va_list start;
	size_t i;
	size_t j;

	CH_NULL(start_list = init_list());
	mod = start_list;
	check_fmt(fmt);
	mod = start_list;
	g_output_symbols = 0;
	va_start(ap, fmt);
	va_copy(start, ap);
	i = 0;
	j = i;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
//						printf("flag = [%s]\nwidth = [%d]\nprecision = [%d]\ntype = [%d]\n"
//							   "num_arg = [%d]\nwidth_num_arg = [%d]\nprec_num_arg = [%d]\n"
//				   "i = [%zu]\nerror = [%i]\n",
//							   mod->flag, mod->width, mod->precision,
//							   mod->type, mod->num_arg, mod->width_num_arg,
//							   mod->prec_num_arg, mod->i, mod->error);
			ft_putnstr_full(fmt + j, (i - j));
			parser(fmt, ap, start, &i);
			i = i + mod->i;
			j = i;
			mod = mod->next;
		}
		i++;
	}
	ft_putstr_full(fmt + j);
	va_end(start);
	va_end(ap);
	del_list(0);
	return (g_output_symbols);
}

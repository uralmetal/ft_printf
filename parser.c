/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:06:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/22 17:40:13 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_width(t_print *mod, va_list ap, const char *fmt, size_t *i)
{
	int j;

	j = 0;
	if (fmt[*i] > '0' && fmt[*i] <= '9')
	{
		mod->width = ft_atoi(fmt + *i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			*i += 1;
	}
	else if (fmt[*i] == '*')
	{
		*i += 1;
		if ((mod->width_num_arg = number_of_argument(fmt, i, 2)) == 0 &&
		(mod->width = va_arg(ap, int)) <= 0)
		{
			while (mod->flag[j] != '0' && mod->flag[j] && mod->flag[j] != '-')
				j++;
			mod->flag[j] = '-';
			mod->width <= -2147483648 ? (mod->width = 0) : (mod->width *= -1);
		}
	}
	else
		mod->width = 0;
}

static void check_precision(t_print *mod, va_list ap, const char *fmt, size_t *i)
{
	if (fmt[*i] == '.')
	{
		*i += 1;
		if (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			mod->precision = ft_atoi(fmt + *i);
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
				*i += 1;
		}
		else if (fmt[*i] == '*')
		{
			*i += 1;
			if ((mod->prec_num_arg = number_of_argument(fmt, i, 3)) == 0)
				mod->precision = va_arg(ap, int);
		}
		else
			mod->precision = 0;
	}
	else
		mod->precision = -1;
}

/*
hh h l ll
d i o u x X
*/

static int check_specif(t_print *mod, const char *fmt, size_t *i)
{
	const char spc[][4] = {"c", "s", "p", "i", "%", "d", "o", "u", "x",
						   "X", "f", "Lf", "hhd", "hhi", "hho", "hhu", "hhx",
						   "hhX", "hd", "hi", "ho", "hu", "hx", "hX",
						   "lf", "ld", "li", "lo", "lu", "lx", "lX",
						   "lld", "lli", "llo", "llu", "llx", "llX", ""};
	int j;
	int size;
	int j_spec;

	j_spec = -1;
	size = 1;
	j = 0;
	while (spc[j][0] != 0 && size < 4)
		if ((ft_strncmp(spc[j], (fmt + *i), size) == 0))
		{
			size++;
			j_spec = j;
		}
		else
			j++;
	if (j_spec == -1)
		return (0);
	mod->type = j_spec;
	*i = *i + ft_strlen(spc[j_spec]);
	return (1);
}


void va_arg_num_int(va_list start, int num_arg, int *value)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		va_arg(start_start, int);
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
		va_arg(start_start, void *);
	*p = va_arg(start_start, void *);
	va_end(start_start);
}

int parser(const char *fmt, va_list ap, va_list start, size_t *i)
{
	t_print mod;
	void *p;

	*i += 1;
	if (fmt[*i] == '%')
		return (1);
	ft_bzero(mod.flag, 6);
	mod.type = -1;
	mod.width = 0;
	mod.precision = -1;
	mod.num_arg = 0;
	mod.width_num_arg = 0;
	mod.prec_num_arg = 0;
	if (check_flags(&mod, fmt, i) == 0)
		return (0);
	check_width(&mod, ap, fmt, i);
	if(mod.width_num_arg != 0)
		va_arg_num_int(start, mod.width_num_arg, &mod.width);
	if (check_flags(&mod, fmt, i) == 0)
		return (0);
	check_precision(&mod, ap, fmt, i);
	if(mod.prec_num_arg != 0)
		va_arg_num_int(start, mod.prec_num_arg, &mod.precision);
	if (check_flags(&mod, fmt, i) == 0)
		return (0);
	clean_flags(&mod);
	if (check_specif(&mod, fmt, i) == 0)
		return (0);
	if (mod.num_arg == 0)
		p = va_arg(ap, void *);
	else
		va_arg_num(start, mod.num_arg, &p);
	if (print(&mod, &p) == 0)
		return (0);
	return (1);
}


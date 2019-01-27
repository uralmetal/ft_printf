/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:06:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/26 20:41:05 by gleonett         ###   ########.fr       */
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
		if ((mod->width_num_arg = number_of_argument(fmt, i)) == 0 &&
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
			if ((mod->prec_num_arg = number_of_argument(fmt, i)) == 0)
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
	const char spc[][4] = {
			/*0*/"c",
			/*1*/"s",
			/*2*/"p",
			/*3*/"i",
			/*4*/"%",
			/*5*/"d",
			/*6*/"o",
			/*7*/"u",
			/*8*/"x",

			/*9*/"X",
			/*10*/"f",
			/*11*/"Lf",
			/*12*/"hhd",
			/*13*/"hhi",
			/*14*/"hho",
			/*15*/"hhu",
			/*16*/"hhx",

			/*17*/"hhX",
			/*18*/"hd",
			/*19*/"hi",
			/*20*/"ho",
			/*21*/"hu",
			/*22*/"hx",
			/*23*/"hX",

			/*24*/"lf",
			/*25*/"ld",
			/*26*/"li",
			/*27*/"lo",
			/*28*/"lu",
			/*29*/"lx",
			/*30*/"lX",

			/*31*/"lld",
			/*32*/"lli",
			/*33*/"llo",
			/*34*/"llu",
			/*35*/"llx",
			/*36*/"llX",

			/*37*/"e",
			/*38*/"g",
			/*39*/"le",
			/*40*/"lg",
			/*41*/"Le",
			/*42*/"Lg",

			/*43*/"G",
			/*44*/"lG",
			/*45*/"LG",
			/*46*/"F",
			/*47*/"lF",
			/*48*/"LF",
			/*49*/"E",
			/*50*/"lE",
			/*51*/"LE",

			/*52*/"S",
			/*53*/"ls",
			/*54*/"C",
			/*55*/"lc",

			/*56*/"a",
			/*57*/"la",
			/*58*/"La",
			/*59*/"A",
			/*60*/"lA",
			/*61*/"LA",

			/*62*/"n",
			/*63*/"D",
			/*64*/"O",
			/*65*/"U",
			/*66*/"zu",
			/*67*/"zi",
			/*68*/"ju",
			/*69*/"ji",
			/*71*/""};
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
	if (j_spec == 5)
		mod->type = 3;
	else if (j_spec == 13)
		mod->type = 12;
	else if (j_spec == 19)
		mod->type = 18;
	else if (j_spec == 26)
		mod->type = 25;
	else if (j_spec == 32)
		mod->type = 31;
	else if (j_spec == 39)
		mod->type = 37;
	else if (j_spec == 40)
		mod->type = 38;
	else if (j_spec == 44)
		mod->type = 43;
	else if (j_spec == 47)
		mod->type = 46;
	else if (j_spec == 50)
		mod->type = 49;
	else if (j_spec == 53)
		mod->type = 52;
	else if (j_spec == 55)
		mod->type = 54;
	else if (j_spec == 63)
		mod->type = 25;
	else if (j_spec == 64)
		mod->type = 27;
	else if (j_spec == 65)
		mod->type = 28;
	else if (j_spec == 66 || j_spec == 68)
		mod->type = 34;
	else if (j_spec == 67 || j_spec == 69)
		mod->type = 32;
	else
		mod->type = j_spec;
	*i = *i + ft_strlen(spc[j_spec]);
	return (j_spec == 4 ? 2 : 1);
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

void va_arg_num_d(va_list start, int num_arg, double *var_d)
{
	int i;
	va_list start_start;

	va_copy(start_start, start);
	i = 0;
	while (++i != num_arg)
		va_arg(start_start, void *);
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
		va_arg(start_start, void *);
	*var_dd = va_arg(start_start, long double);
	va_end(start_start);
}

int parser(const char *fmt, va_list ap, va_list start, size_t *i)
{
	t_print mod;
	void *p;
	int *spec_n;
	double var_d;
	long double var_dd;


	*i += 1;
	p = NULL;
	var_d = 0;
	var_dd = 0;
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
	if ((check_specif(&mod, fmt, i)) == 0)
		return (0);
	else if (mod.type == 4)
		return (print(&mod, NULL, 0, 0));

	if (mod.type == 10 ||mod.type == 24 || mod.type == 37 || mod.type == 38 ||
		mod.type == 46 || mod.type == 49)
		if (mod.num_arg == 0)
			var_d = va_arg(ap, double);
		else
			va_arg_num_d(start, mod.num_arg, &var_d);
	else if (mod.type == 11 || mod.type == 41 || mod.type == 42 ||
	mod.type == 48 || mod.type == 51)
		if (mod.num_arg == 0)
			var_dd = va_arg(ap, long double);
		else
			va_arg_num_dd(start, mod.num_arg, &var_dd);
	else
		if (mod.num_arg == 0)
			p = va_arg(ap, void *);
		else
			va_arg_num(start, mod.num_arg, &p);
	if (mod.type == 62)
	{
		spec_n = p;
		*spec_n = g_output_symbols;
		return (1);
	}
	if (print(&mod, &p, var_d, var_dd) == 0)
		return (0);
	return (1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:20 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/01 15:11:31 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_width(t_print *mod, const char *fmt, size_t *i)
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
		mod->width_num_arg = number_of_argument(fmt, i);
	}
	else
		mod->width = 0;
	return (0);
}

static int check_precision(t_print *mod, const char *fmt, size_t *i)
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
			mod->prec_num_arg = number_of_argument(fmt, i);
		}
		else
			mod->precision = 0;
	}
	else
		mod->precision = -1;
	return (0);
}

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
			/*70*/"jx",
			/*71*/"b",
			/*72*/"hb",
			/*73*/"hhb",
			/*74*/"lb",
			/*75*/"llb",
			/*76*/"k",
			/*77*/"r",
			/*78*/"jd",
			/*79*/"zd",
			/*80*/"hU",
			/*81*/"lO",
			/*82*/"lU",
			/*83*/"lD",
			/*84*/"llO",
			/*85*/"hO",
			/*86*/"hD",
			/*87*/"hhO",
			/*88*/"hhU",
			/*89*/"hhD",
			/*90*/"hhC",
			/*91*/"hhS",
			/*92*/"jo",
			/*93*/"jX",
			/*94*/"jO",
			/*95*/"zo",
			/*96*/"zx",
			/*97*/"zX",
			/*98*/"zO",
			/*99*/"lp",
			/*81*/""};
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
		{
			j++;
		}
	if (j_spec == -1 && mod->width < 2)
		return (1);
	else if (j_spec == -1)
	{
		mod->type = 0;
		mod->precision = fmt[*i];
		*i += 1;
		mod->error = 2;
		return (0);
	}
	if (j_spec == 5)
		mod->type = 3;
	else if (j_spec == 99)
		mod->type = 2;
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
	else if (j_spec == 53 || j_spec == 91)
		mod->type = 52;
	else if (j_spec == 55 || j_spec == 90)
		mod->type = 54;
	else if (j_spec == 63)
		mod->type = 25;
	else if (j_spec == 64)
		mod->type = 27;
	else if (j_spec == 65)
		mod->type = 28;
	else if (j_spec == 66 || j_spec == 68 || j_spec == 80 || j_spec == 82 ||
			j_spec == 88)
		mod->type = 34;
	else if (j_spec == 67 || j_spec == 69 || j_spec == 83 || j_spec == 78 ||
			j_spec == 86 || j_spec == 79 || j_spec == 89)
		mod->type = 31;
	else if (j_spec == 70 || j_spec == 96)
		mod->type = 35;
	else if (j_spec == 81 || j_spec == 84 || j_spec == 85 || j_spec == 87 ||
	j_spec == 92 || j_spec == 94 || j_spec == 95 || j_spec == 98)
		mod->type = 33;
	else if (j_spec == 93 || j_spec == 97)
		mod->type = 36;
	else
		mod->type = j_spec;
	*i = *i + ft_strlen(spc[j_spec]);
	return (0);
}
int	check_fmt(const char *fmt)
{
	size_t i;
	size_t j;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			j = i;
			check_flags(mod, fmt, &i);
			CH_ERROR(check_width(mod, fmt, &i));
			check_flags(mod, fmt, &i);
			CH_ERROR(check_precision(mod, fmt, &i));
			check_flags(mod, fmt, &i);
			clean_flags(mod);
			CH_ERROR(check_specif(mod, fmt, &i));
			mod->i = i - j;
			mod->next = init_list();
			mod = mod->next;
		}
		else
			i++;
	}
	mod = start_list;
	return (0);
}

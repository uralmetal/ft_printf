/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:20 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/03 19:28:46 by gleonett         ###   ########.fr       */
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
	else
		mod->width = 0;
	if (fmt[*i] == '*')
	{
		*i += 1;
		mod->width_num_arg = number_of_argument(fmt, i);
		j++;
	}
	if (fmt[*i] > '0' && fmt[*i] <= '9')
	{
		mod->width = ft_atoi(fmt + *i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			*i += 1;
	}
	else if (j > 0)
		mod->width = 0;
	return (0);
}

static int check_precision(t_print *mod, const char *fmt, size_t *i)
{
	if (fmt[*i] == '.')
	{
		while (fmt[*i] == '.')
		{
			if (fmt[*i + 1] == '.')
				*i += 1;
			*i += 1;
			if (fmt[*i] >= '0' && fmt[*i] <= '9')
			{
				mod->precision = ft_atoi(fmt + *i);
				while (fmt[*i] >= '0' && fmt[*i] <= '9')
					*i += 1;
			}
			else
				if (fmt[*i] == '*')
				{
					*i += 1;
					mod->prec_num_arg = number_of_argument(fmt, i);
				}
				else
					mod->precision = 0;
		}
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
			/*100*/"llU",
			/*101*/"llD",
			/*102*/"jU",
			/*103*/"jD",
			/*104*/"zU",
			/*105*/"zD",
			/*106*/""};
	int j;
	char *ret[20];

	j = 0;
	ft_bzero(ret, 20);
	check_type(fmt, ret, i);
	if (*ret == '\0')
		j = 106;
	else
		while (ft_strcmp(ret, spc[j]) != 0)
			j++;
	if (j == 106 && mod->width < 2)
		return (1);
	else if (j == 106)
	{
		mod->type = 0;
		mod->precision = fmt[*i];
		*i += 1;
		mod->error = 2;
		return (0);
	}
	if (j == 5)
		mod->type = 3;
	else if (j == 99)
		mod->type = 2;
	else if (j == 13)
		mod->type = 12;
	else if (j == 19)
		mod->type = 18;
	else if (j == 26)
		mod->type = 25;
	else if (j == 32 || j == 101)
		mod->type = 31;
	else if (j == 39)
		mod->type = 37;
	else if (j == 40)
		mod->type = 38;
	else if (j == 44)
		mod->type = 43;
	else if (j == 47)
		mod->type = 46;
	else if (j == 50)
		mod->type = 49;
	else if (j == 53 || j == 91)
		mod->type = 52;
	else if (j == 55 || j == 90)
		mod->type = 54;
	else if (j == 63)
		mod->type = 25;
	else if (j == 64)
		mod->type = 27;
	else if (j == 65)
		mod->type = 28;
	else if (j == 66 || j == 68 || j == 80 || j == 82 ||
			j == 88 || j == 100 || j == 102 || j == 105)
		mod->type = 34;
	else if (j == 67 || j == 69 || j == 83 || j == 78 || j == 86 || j == 79
	|| j == 89 || j == 103 || j == 104)
		mod->type = 31;
	else if (j == 70 || j == 96)
		mod->type = 35;
	else if (j == 81 || j == 84 || j == 85 || j == 87 ||
	j == 92 || j == 94 || j == 95 || j == 98)
		mod->type = 33;
	else if (j == 93 || j == 97)
		mod->type = 36;
	else
		mod->type = j;
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
			CH_ERROR(check_specif(mod, fmt, &i));
			clean_flags(mod);
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

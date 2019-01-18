/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/18 18:29:38 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void check_flgs_width(t_print *mod, va_list *ap, const char *fmt, size_t *i)
{
	char flgs[6] = "-+ #0";
	int j;

	/*Флаги*/
	j = 0;
	*i += 1;
	while (flgs[j] && fmt[*i] != flgs[j])
		j++;
	if (j < 5)
	{
		mod->flag = flgs[j];
		*i += 1;
	}
	else
		mod->flag = '\0';
	/*Ширина*/
	if (fmt[*i] > '0' && fmt[*i] <= '9')
	{
		mod->width = ft_atoi(fmt + *i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			*i += 1;
	}
	else if (fmt[*i] == '*')
	{
		if ((mod->width = va_arg(*ap, int)) <= 0)
		{
			mod->flag = '-';
			mod->width *= -1;
		}
		*i += 1;
	}
	else
		mod->width = 0;
}

static void check_precision(t_print *mod, va_list *ap, const char *fmt, size_t *i)
{
	/*Точность*/
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
			mod->precision = va_arg(*ap, int);
			*i += 1;
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
	const char spc[][4] = {"c", "s", "p", "%", "d", "i", "o", "u", "x",
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
	{
		if ((ft_strncmp(spc[j], (fmt + *i), size) == 0))
		{
			size++;
			j_spec = j;
		}
		else
			j++;
	}
	if (j_spec == -1)
		return (0);
	ft_strcpy(mod->type, spc[j_spec]);
	*i = *i + ft_strlen(spc[j_spec]);
	return (1);
}

static int parser(const char *fmt, va_list *ap, size_t *i)
{
	t_print mod;
	get_output fnc;

	check_flgs_width(&mod, ap, fmt, i);
	check_precision(&mod, ap, fmt, i);
	if (check_specif(&mod, fmt, i) == 0)
	{
		printf("Нет такого спецификатора, йобик");
		return (0);
	}
	printf("flag = [%c]\nwidth = [%d]\nprecision = [%d]\ntype = [%s]\n",
			mod.flag,mod.width, mod.precision, mod.type);
	if ((fnc = get_function(mod)) == NULL)
	{
		printf("Пока нет такой функции, напиши ее, заебал <3");
		return (0);
	}
	void *p = va_arg(*ap, void *);
	ft_putstr(fnc(&p));
	return (1);
}

void	ft_printf(const char *fmt, ...)
{
	va_list ap;
	size_t i;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (parser(fmt, &ap, &i) == 0)
				return ;
		}
		else
		{
			ft_putchar(fmt[i]);
			i++;
		}
	}
	va_end(ap);
}
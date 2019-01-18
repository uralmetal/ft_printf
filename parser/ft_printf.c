/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/18 12:41:11 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void check_flgs_width(t_print *mod, va_list *ap, const char *fmt, int *i)
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
		mod->width = va_arg(*ap, int);
		*i += 1;
	}
	else
		mod->width = 0;
}

static void check_precision(t_print *mod, va_list *ap, const char *fmt, int *i)
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

static int parser(const char *fmt, va_list *ap, int *i)
{
	const char spc[4] ="csp";
	int j;
	t_print mod;
	void *c;

//	printf("Do: i = [%d]\n", *i);
	check_flgs_width(&mod, ap, fmt, i);
	check_precision(&mod, ap, fmt, i);
	printf("flag = [%c]\nwidth = [%d]\nprecision = [%d]\n", mod.flag, mod
	.width, mod.precision);
	//	check_size(&mod, fmt, &i);
	//	print_res(&mod, fmt, &i);
	j = 0;
	while (spc[j] != fmt[*i] && spc[j])
		j++;
	if (spc[j] == '\0')
		return (-1);
	if (spc[j] == 'c')
	{
		mod.type[0] = 'c';
		c = va_arg(*ap, void *);
		print(mod, &c);
	}
	else if (spc[j] == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (spc[j] == 'p')
		ft_putstr(get_pointer(va_arg(*ap, void *)));
	else
		ft_putstr("Wrong specificator!");
	*i += 1;								//1 - пока есть толькоодносимвольные спецификаторы
	return (1);
}

void	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int i;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (parser(fmt, &ap, &i) == -1)
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
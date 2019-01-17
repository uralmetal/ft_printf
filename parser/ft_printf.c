/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/17 17:53:05 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:21:19 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/16 17:27:24 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static int parser(const char fmt, va_list *ap, int j)
{
	const char spc[4] ="csp";
	int i;
	t_print mod;
	void *c;

	i = 0;

	while (spc[i] != fmt && spc[i])
	{
		i++;
	}
	if (spc[i] == '\0')
	{
		return (-1);
	}
	if (spc[i] == 'c')
	{
		mod.type[0] = 'c';
		c = va_arg(*ap, void *);
		print(mod, &c);
	}
	else if (spc[i] == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (spc[i] == 'p')
	{
		ft_putstr(get_pointer(va_arg(*ap, void *)));
	}
	else
	{
		ft_putstr("Wrong specificator!");
	}
	return (j + 2);
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
			if ((i = parser(fmt[i + 1], &ap, i)) == -1)
				return ;
		}
		else
		{
			ft_putchar(fmt[i]);
			i++;
		}
	}
	va_end(ap);
	//	foo ("sdc", "az", 2, 'a');
}
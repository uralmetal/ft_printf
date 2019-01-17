/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/16 19:52:07 by gleonett         ###   ########.fr       */
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

static void foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	while (*fmt)
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
}

static int parser(const char fmt, va_list *ap, int j)
{
	const char specificators[4] ="csp";
	int i;
	char c;

	i = 0;
	//	printf("%c", fmt);
	while (specificators[i] != fmt && specificators[i])
	{
		//		printf("%c", specificators[i]);
		i++;
	}
	if (specificators[i] == '\0')
	{
		return (-1);
	}
	else
	{
//		ft_putchar(specificators[i]);
//		if (specificators[i] == 'c')
//		{
//			ft_putchar(va_arg(*ap, int));
//		}
		if (specificators[i] == 's')
			ft_putstr(va_arg(*ap, char *));
		else if (specificators[i] == 'p')
			ft_putstr(get_pointer(va_arg(*ap, void *)));
	}
	return (j + 1);
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
			if ((i = parser(fmt[i + 1], &ap, i) == -1))
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
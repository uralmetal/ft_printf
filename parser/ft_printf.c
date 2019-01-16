/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/16 17:45:16 by gleonett         ###   ########.fr       */
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

static char	*parser(char *fmt, va_list *ap)
{
	const char specificators[4][] ={"c", "s", "p", NULL};
	const 
	int i;

	i = 0;
	while (specificators[i][0] != *fmt && specificators[i] != NULL)
		i++;
	if (specificators[i] == NULL)
		return (0);
	if ()

}

void	ft_printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = parser(fmt, &ap);
		}
		else
			ft_putchar(*fmt++);
	}
	va_end(ap);
	//	foo ("sdc", "az", 2, 'a');
}
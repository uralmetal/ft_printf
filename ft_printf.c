/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/19 19:22:27 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
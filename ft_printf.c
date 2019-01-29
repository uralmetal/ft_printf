/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/29 20:04:50 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	va_list start;
	size_t i;
	size_t j;

	g_output_symbols = 0;
	va_start(ap, fmt);
	va_copy(start, ap);
	i = 0;
	j = i;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ft_putnstr_full(fmt + j, (i - j));
			parser(fmt, ap, start, &i);
			j = i;
		}
		i++;
	}
	ft_putstr_full(fmt + j);
	va_end(start);
	va_end(ap);
	return (g_output_symbols);
}
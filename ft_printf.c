/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:38:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/21 17:18:21 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list ap;
	size_t i;
	size_t j;

	i = 0;
	j = i;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ft_putnstr_full(fmt + j, (i - j));
			parser(fmt, &ap, &i);
			j = i;
		}
		i++;
	}
	ft_putstr_full(fmt + j);
	va_end(ap);
}